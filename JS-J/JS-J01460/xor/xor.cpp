#include<bits/stdc++.h>
using namespace std;
int a[2010][2010],b[200010],n;
void solve(int k){
    int ans=0;
    if(k==1){
        for(int i=1;i<=n;i++)ans+=b[i];
        cout<<ans;
        return;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0)ans++;
        else if(b[i-1]==1){
            ans++;
            b[i]=0;
        }
    }
    cout<<ans;
    return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int m,f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]>1)f=0;
    }
    if(f==1){
        solve(m);
        return 0;
    }
    for(int i=1;i<=n;i++)a[i][i]=b[i];
    for(int i=1;i<=n;i++){
            int t=b[i];
            for(int k=i+1;k<=n;k++){
                t=t^b[k];
                a[i][k]=t;
            }
    }
    int mx=1,cnt=0;
    for(int j=1;j<=n;j++){
        for(int i=mx;i<=j;i++){
            if(a[i][j]==m){
                mx=j+1;
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
/*9:53 60~65pts*/
