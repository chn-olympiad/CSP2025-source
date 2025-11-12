#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool yin=true;
int n,q,ss[N],qq[N],hh[N];
string as[N],bs[N],aq,bq;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>as[i]>>bs[i];
        int x,y;hh[i]=as[i].size();
        for(int j=0;j<hh[i];j++){
            if(as[i][j]=='b')   x=j;
            if(bs[i][j]=='b')   y=j;
        }//
        ss[i]=y-x;qq[i]=x;
    }
    while(q--){
        cin>>aq>>bq;
        int len=aq.size(),x,y,c,qqc;
        for(int i=0;i<len;i++){
            if(aq[i]=='b')  x=i;
            if(bq[i]=='b')  y=i;
        }
        c=y-x;qqc=x;//cout<<qq[i]<<endl;cout<<c<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(ss[i]==c&&qq[i]<=qqc&&hh[i]-qq[i]<=len-qqc)    ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}