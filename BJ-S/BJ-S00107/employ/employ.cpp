#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define db
const ll maxn=502;
ll g[maxn],f[maxn],ma[maxn],s=0,n,m,p=998244353,x[maxn];
ll y[maxn],o=0,z[maxn];
char str[maxn]; 
void r(ll a){
    if(a-o-1==m){
        s=(s+x[n-a+1])%p;
        #ifdef db
        cout<<a<<"#"<<o<<endl;
        for(int i=1;i<=n;i++)
            cout<<y[i]<<" ";
        cout<<endl;
        #endif
        return;
    }
    if(a==n+1){
        return;
    }
    for(int i=1;i<=n;i++){
        if(ma[i])
            continue;
        ma[i]=1;
        y[a]=i;
        if(!f[a]||g[i]<=o){
            o++;
            r(a+1);
            o--;
        }
        else
            r(a+1);
        ma[i]=0;
        y[a]=0;
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int l;
    x[0]=1;
    for(int i=1;i<=500;i++)
        x[i]=(x[i-1]*i)%p;
    cin>>n>>m;
    cin>>str;
    l=strlen(str);
    for(int i=0;i<l;i++)
        f[i+1]=str[i]-'0';
    for(int i=1;i<=n;i++)
        cin>>g[i];
    r(1);
    cout<<s<<endl;
    return 0;
}