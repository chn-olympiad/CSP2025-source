#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
int n,m,a[N],idx[N],ans;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    n=read(),m=read();
    cin>>s;
    for(int i=1;i<=n;i++) a[i]=read(),idx[i]=i;
    s="@"+s;
    do{
        int cnt=0,lst=0;
        for(int i=1;i<=n;i++){
            if(cnt>=a[idx[i]]){
                cnt++;
                continue;
            }
            if(s[i]=='1') lst++;
            else cnt++;
            // cout<<idx[i]<<' ';
        }
        // cout<<'\n';
        if(lst>=m) ans++;
    }while(next_permutation(idx+1,idx+n+1));
    cout<<ans<<'\n';
    return 0;
}