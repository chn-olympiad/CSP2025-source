#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans,l[N],r[N],sz[N];
string s[N][2],df[N][2],t[2];
int main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        int sz=s[i][0].size(),l=-1,r=-1;::sz[i]=sz;
        for(int j=0;j<sz;j++)if(s[i][0][j]!=s[i][1][j]){l=j;break;}
        for(int j=sz-1;~j;j--)if(s[i][0][j]!=s[i][1][j]){r=j;break;}
        ::l[i]=l,::r[i]=r;
        if(l>=0) df[i][0]=s[i][0].substr(l,r-l+1),df[i][1]=s[i][1].substr(l,r-l+1);
        else df[i][0]=df[i][1]="";
    }
    while(q--){
        cin>>t[0]>>t[1],ans=0;
        if(t[0].size()!=t[1].size()){cout<<"0\n";continue;}
        int sz=t[0].size(),l=-1,r=-1;
        for(int i=0;i<sz;i++)if(t[0][i]!=t[1][i]){l=i;break;}
        for(int i=sz-1;~i;i--)if(t[0][i]!=t[1][i]){r=i;break;}
        string ta,tb;
        if(l>=0) ta=t[0].substr(l,r-l+1),tb=t[1].substr(l,r-l+1); else ta=tb="";
        for(int i=1;i<=n;i++) if(ta==df[i][0]&&tb==df[i][1]){
            if(l-::l[i]<0||l-::l[i]+::sz[i]>sz) continue;
            bool b=1;
            for(int x=0,y=l-::l[i];x<::sz[i];x++,y++)
                if(t[0][y]!=s[i][0][x]){b=0;break;}
            if(!b) continue;
            for(int x=0,y=l-::l[i];x<::sz[i];x++,y++)
                if(t[1][y]!=s[i][1][x]){b=0;break;}
            if(!b) continue;
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}