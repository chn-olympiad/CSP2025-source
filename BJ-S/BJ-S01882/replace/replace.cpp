#include<bits/stdc++.h>
using namespace std;
#define int long long
string sx[200005],sy[200005],lbx[200005],lby[200005];

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        string st1="",st2="";
        bool flag=0;
        int id=1,dif1,dif2;
        for(int j=0;j<x.size();j++){
            if(x[j]!=y[j]){
                dif1=j;
                break;
            }
        }
        for(int j=x.size()-1;j>=0;j--){
            if(x[j]!=y[j]){
                dif2=j;
                break;
            }
        }
        for(int j=dif1;j<=dif2;j++){
            st1+=x[j],st2+=y[j];
        }
        sx[i]=st1,sy[i]=st2;
    }
    while(q--){
        int ans=0;
        string tx,ty;
        cin>>tx>>ty;
        if(tx.size()!=ty.size()){
            cout<<0<<endl;
        }
        else{
            int id=1,dif1,dif2;
            string st1="",st2="";
            bool flag=0;
            for(int j=0;j<tx.size();j++){
                if(tx[j]!=ty[j]){
                    dif1=j;
                    break;
                }
            }
            for(int j=tx.size()-1;j>=0;j--){
                if(tx[j]!=ty[j]){
                    dif2=j;
                    break;
                }
            }
            for(int i=0;i<tx.size();i++){
                if(i==dif1){
                    flag=1;
                    id=2;
                }
                else if(i==dif2){
                    flag=0;
                    st1+=tx[i],st2+=ty[i];
                    id=1;
                }
                if(flag){
                    st1+=tx[i],st2+=ty[i];
                }
            }
            //cout<<st1<<" "<<st2<<endl;
            for(int i=1;i<=n;i++){
                if(st1==sx[i]&&st2==sy[i]){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
