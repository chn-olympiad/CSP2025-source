#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,p,a[N],maxx,ans,c,c1;
void dfs(int x,int sum,int l,int g){
    for(int i=x;i<=n;i++){
        if(l==1){
            sum=a[i];
            l=0;
        }else{
            sum^=a[i];
        }
        if(sum==p){
            if(i==n){
                ans=max(ans,g+1);
                return ;
            }
            for(int d=x+1;d<=n;d++){
                dfs(d,0,1,g+1);
            }
        }
    }
    ans=max(ans,g);
    return ;

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            c=1;
        }
        if(a[i]!=1&&a[i]!=0){
            c1=1;
        }
    }
    if(p==0&&c==0){
       cout<<n/2;
       return 0;
    }
    if(p==1&&c1==0){
            int h=0;
        for(int i=2;i<=n;i++){
            if(a[i]==1&&a[i-1]!=0&&a[i+1]!=0){
                h++;
            }else if(a[i]==1&&a[i-1]==0){
                h++;
            }else if(a[i]==0&&a[i-1]==1){
                h++;
            }
        }
        cout<<h;
        return 0;
    }
    dfs(1,0,1,0);
    cout<<ans;
    return 0;
}
