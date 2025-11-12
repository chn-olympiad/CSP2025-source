#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],b[505],d[505];
string s;
const long long mod=998244353;
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int fi=-1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        d[i]=n;
        b[i]=s[i-1]-'0';
    }
    sort(c+1,c+n+1);
    if(fi<0) cout<<0<<endl;
    else{
        ans=n*(n-1)/2;
        int sum=0,t=0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                    d[i]=d[i-1];
                if(c[i]>t){
                    sum++;
                }
                else {
                    while(c[i]<=t){
                        i++,ans--;
                    }
                }
            }
            else t++;
        }
        if(sum>m) cout<<ans%mod;
        int sum=0,f=1,t;
        for(int i=1;i<=n&&f;i++){
            if(c[i]>b[i]&&s[i-1]>0) sum++;

            if(sum>m) ans++,f=0,t=i;
        }
    }
    return 0;
}

