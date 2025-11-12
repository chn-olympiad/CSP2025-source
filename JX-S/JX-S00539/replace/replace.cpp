#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int nn=2e5+5;
int n,q,len[nn],to;
string s[2][nn];
string t[2];
vector<ull>g[nn];
bool pd(int op,int sp,int id,int l,int x,int y){
    for(int i=x,j=l;i<=y;i++,j++){
        if(t[sp][i]!=s[op][id][j])return 0;
    }
    return 1;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[0][i]>>s[1][i];
        s[0][i]=" "+s[0][i];
        s[1][i]=" "+s[1][i];
        len[i]=s[0][i].size()-1;
    }
    while(q--){
        to++;
        cin>>t[0]>>t[1];
        t[0]=" "+t[0],t[1]=" "+t[1];
        int ls=t[0].size()-1,lb=t[1].size()-1;
        if(ls!=lb){
            cout<<0<<'\n';
            continue;
        }
        int ed=0;
        for(int i=ls;i;i--){
            if(t[0][i]!=t[1][i]){
                ed=i;
                break;
            }
        }
        int fl=0,st=0;
        for(int i=1;i<=ls;i++){
            if(t[0][i]!=t[1][i] && fl==0)fl=1,st=i;
            if(i==ed)break;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=len[i];j++){
                if(pd(0,0,i,j,st,ed)){

                    if(j-st<0 || (len[i]-j)<(ls-ed))continue;

                    if(pd(0,0,1,len[i],st-(j-1),ed+(len[i]-j-(ed-st)))){
                        //if(i==1 && to==1){
                          //  cout<<"yes"<<" "<<st-(j-1)<<" "<<ed+(len[i]-(j+ed-st))<<'\n';
                        //}
                        if(pd(1,1,1,len[i],st-(j-1),ed+(len[i]-j-(ed-st))))ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
