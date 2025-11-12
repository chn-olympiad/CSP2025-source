#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int s[550],c[550],lst[550];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==m){
        for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            if(c=='0'){
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=n;i++){
            int s;
            cin>>s;
            if(s==0){
                cout<<0;
                return 0;
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%MOD;
        cout<<ans<<'\n';
        return 0;
    }
    if(m==1){
        int ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%MOD;
        int f=0;
        for(int i=1;i<=n;i++){
            char ch;
            cin>>ch;
            s[i]=(ch=='1');
        }
        for(int i=1;i<=n;i++)cin>>c[i];
        sort(c+1,c+n+1);
        int now=0;
        for(int i=1;i<=n;i++){
            lst[c[i]]=i;
            if(c[i]<=now||s[i]==0){
                now++;
            }else{
                cout<<ans;
                return 0;
            }
        }
        for(int i=1;i<=n;i++){
            if(lst[i]==0)lst[i]=lst[i-1];
            //cout<<lst[i]<<" ";
        }
        //cout<<'\n';
        int ans1=1;
        for(int i=1;i<=n;i++){
            if(s[i])ans1=ans1*(lst[i]-i+1)%MOD;
            else ans1=ans1*(n-i+1)%MOD;
            //cout<<ans1<<'\n';
        }
        cout<<(ans-ans1+MOD)%MOD;
    }
    return 0;
}


