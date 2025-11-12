#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=2e7+5;
int n,q;
string s[N][2];
int pi[L];
long long ans=0;
int main(){
    freopen("TT.in","r",stdin);
    freopen("TT.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        ans=0;
        string ta,tb;cin>>ta>>tb;
        for(int j=1;j<=n;j++){
            string hc=s[j][0]+'#'+ta;
            int l1=ta.size(),l2=s[j][0].size(),l=l1+l2+1;
            for(int d=1;d<l;d++){
                int h=pi[d-1];
                while(h>0&&hc[d]!=hc[h])h=pi[h-1];
                (hc[d]==hc[h])?pi[h]=h+1:0;
                if(d>=l2+1&&pi[d]==l1){
                    bool vis=0;
                    for(int k=d-(l2<<1)+1,bk=0;k<=d-l2+1;k++,bk++){
                        if(tb[k]!=s[j][1][bk])vis=1;
                    }
                    if(!vis)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
