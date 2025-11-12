#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
string a[maxn],b[maxn];
int n,q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int ppp=1;ppp<=q;ppp++){
        string x,y; cin>>x>>y;
        int ans=0;
        for(int i=1;i<=n;i++){
            string nst=x;
            int fd=x.find(a[i]);
            if(fd<=x.length() && fd>=0){
                for(int j=fd;j<b[i].length()+fd;j++) nst[j]=b[i][j-fd];
            }
            if(nst==y) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
