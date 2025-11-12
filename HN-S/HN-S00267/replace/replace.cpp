#include<bits/stdc++.h>
#define int long long
#define N 5000005
#define P 139
#define mod 100000000073
#define x first
#define y second
using namespace std;
int n,m,f[N][2];
pair<string,string> a[N];
int h[N][2],p[N];
int h2[N];
int get(int l,int r){
    return (h2[r]-h2[l-1]*p[r-l+1]%mod+mod)%mod;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    p[0]=1;
    for(int i=1;i<=5000002;i++) p[i]=p[i-1]*P%mod;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1,[](pair<string,string> x,pair<string,string> y){return x.first.size()<y.first.size();});
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].first.size();j++){
            h[i][0]=(h[i][0]*P%mod+a[i].first[j])%mod;
            h[i][1]=(h[i][1]*P%mod+a[i].second[j])%mod;
            // cout<<j<<" "<<h[i][1]<<endl;
        }
    }
    while(m--){
        string s,t;
        cin>>s>>t; int res=0;
        if(s.size()^t.size()){
            cout<<0<<"\n";
            continue;
        }
        s=" "+s;
        h2[0]=0;
        for(int i=1;i<s.size();i++){
            h2[i]=(h2[i-1]*P%mod+s[i])%mod;
            // cout<<i<<' '<<h2[i]<<endl;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]!=t[i-1]){
                for(int j=1;j<=n;j++){
                    // if(i+a[j].first.size()>s.size()) break;
                    // cout<<i<<" "<<get(i,i+a[j].first.size()-1)<<' '<<h[j][0]<<endl;
                    
                    if(get(i,i+a[j].first.size()-1)!=h[j][0]) continue;
                    string tmp;
                    for(int l=1;l<i;l++) tmp+=s[l];
                    tmp+=a[j].second;
                    for(int l=i+a[j].first.size();l<s.size();l++) tmp+=s[l];
                    if(tmp==t) res++;
                }
                break;
            }
            else{
                for(int j=1;j<=n;j++){
                    // if(i+a[j].first.size()>s.size()) break;
                    // cout<<get(i,i+a[j].first.size()-1)<<' '<<h[j][0]<<endl;
                    if(get(i,i+a[j].first.size()-1)!=h[j][0]) continue;
                    string tmp;
                    for(int l=1;l<i;l++) tmp+=s[l];
                    tmp+=a[j].second;
                    for(int l=i+a[j].first.size();l<s.size();l++) tmp+=s[l];
                    if(tmp==t) res++;
                }
            }
        }
        // int res=0;
        // for(int i=1;i<s.size();i++){
        //     string tmp;
        //     for(int j=1;j<=n;j++){
        //         if(i+a[j].first.size()>s.size()) continue;
        //         bool f=1;
        //         for(int k=0;k<a[j].first.size();k++) if(s[i+k]!=a[j].first[k]){
        //             f=0;
        //             break;
        //         }
        //         if(f){
        //             string tmp;
        //             for(int l=1;l<i;l++) tmp+=s[l];
        //             tmp+=a[j].second;
        //             for(int l=i+a[j].first.size();l<s.size();l++) tmp+=s[l];
        //             if(tmp==t) res++;
        //         }
        //     }
        // }
        cout<<res<<"\n";
    }
}