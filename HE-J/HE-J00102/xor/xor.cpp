#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long sum[500010];
struct Node{
    int x;
    int y;
};
vector<Node> num;
bool cmp(Node r,Node p){
    return r.x-r.y+1<p.x-p.y+1;
}
bool vis[500010];
bool flagg[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    sum[1]=a[1];
    sum[0]=0;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(flagg[j]==0){
                int s=sum[i]^sum[j-1];
                if(s==k){
                    flagg[j]=1;
                    Node k;
                    k.x=i;
                    k.y=j;
                    num.push_back(k);
                    break;
                }
            }
        }
    }
    sort(num.begin(),num.end(),cmp);
    long long ans=0;
    for(int i=0;i<num.size();i++){
        int flag=1;
        for(int j=num[i].y;j<=num[i].x;j++){
            if(vis[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            ans++;
            for(int j=num[i].y;j<=num[i].x;j++){
                vis[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
