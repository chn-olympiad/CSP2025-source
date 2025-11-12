#include<bits/stdc++.h>
using namespace std;
int n,k,mx=0,flag;
int a[500005];
int s[500005];
struct Node{
    int ed;
    int sum;
};
vector<Node> v[500005];
void dfs(int in,int sum){
    for(int i=0;i<v[in].size();i++){
        Node h=v[in][i];
        if(h.sum==k){
            mx=max(mx,sum+1);
            for(int j=h.ed+1;j<=n;j++){
                if(v[j].size()!=0){
                    dfs(j,sum+1);
                }
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    int sum1=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=0&&a[i]!=1){
            flag=1;
        }
        if(a[i]==1)sum1++;
        s[i]=(s[i-1]^a[i]);
    }
    if(flag){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if((s[j]^s[i-1])==k){
                    v[i].push_back({j,(s[j]^s[i-1])});
                }
            }
        }
        for(int i=1;i<=n;i++){
            dfs(i,0);
        }
    }else{
        if(k==0)mx=n-sum1;
        else if(k==1)mx=sum1;
    }

    cout<<mx;
    return 0;
}
