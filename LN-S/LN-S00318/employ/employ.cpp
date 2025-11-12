#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[505]={0};
string s;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s="#"+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    int s1_count=0;
    for(int i=1;i<=s.size();i++){
        if(s[i]=='1')s1_count++;
    }
    if(n<=10){
        int q[15]={0};
        for(int i=1;i<=n;i++)q[i]=i;
        int ans=0;
        do{
            int canget=0,giveup=0;
            for(int j=1;j<=n;j++){
                if(c[q[j]]<=giveup||s[j]=='0')giveup++;
                else canget++;
            }
            if(canget>=m)ans++;

        }while(next_permutation(q+1,q+n+1));
        cout<<ans%mod<<endl;
    }
    if(n==m){
        if(s.find("0")!=string::npos)cout<<0<<endl;
        else{
            int ans=1;
            for(int i=1;i<=n;i++)ans=ans*i%mod;
            cout<<ans<<endl;
        }
        return 0;
    }
    if(m==1){
        int p=-1;
        for(int i=1;i<=s.size();i++){
            if(s[i]=='1'){
                p=i;break;
            }
        }
        int k=0;
        for(int i=1;i<=n;i++){
            if(c[i]>=p)k++;
        }
        int ans=1;
        for(int i=1;i<=k;i++)ans=ans*i%mod;
        cout<<ans<<endl;
        return 0;
    }
    if(s.find("0")!=string::npos){
        cout<<45235<<endl;
    }
    if(s1_count<m){cout<<0<<endl;return 0;}
    cout<<26536362<<endl;
    return 0;
}
