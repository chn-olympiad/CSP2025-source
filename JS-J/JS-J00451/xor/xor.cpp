#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],is_visited[500010],ans;
int cnt(int l,int length){
    bool flag=true;
    long long tot;
    for(int i=l;i<l+length;i++){
        if(is_visited[i]){
            flag=false;
            break;
        }
        if(i==l) tot=a[i];
        else tot=tot^a[i];
    }
    if(flag==true) return tot;
    else return -1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==k){
            is_visited[i]=1;
            ans++;
        }
    }
    for(int i=1;i<=n-1;i++){
        if(is_visited[i]) continue;
        for(int j=2;i+j-1<=n;j++){
            if(cnt(i,j)==k){
                ans++;
                for(int k=i;k<i+j;k++) is_visited[k]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
