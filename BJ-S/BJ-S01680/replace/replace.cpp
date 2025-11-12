#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N],b[N],c,d;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    while(q--){
        int ans=0;
        cin>>c>>d;
        int m=c.size(),x,y;
        for(int i=1;i<=m;i++)if(c[i]=='b'){x=i;break;}
        for(int i=1;i<=m;i++)if(d[i]=='b'){y=i;break;}
        for(int i=1;i<=n;i++){
            int m=a[i].size(),id;
            for(int j=1;j<=m;i++)if(a[i][j]=='b'){id=i;break;}
            if(b[i][id+y-x]=='b')ans++;
        }cout<<ans<<'\n';
    }
    return 0;
}
