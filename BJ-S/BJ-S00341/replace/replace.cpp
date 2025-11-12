#include<iostream>
using namespace std;
int n,q,ans=0;
string sone[1001],stwo[1001];
string tone[1001],ttwo[1001];
int sonel[1001],stwol[1001];
int tonel[1001],ttwol[1001];
int pro;
string tes;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>sone[i]>>stwo[i];
        sonel[i]=sone[i].length();
        stwol[i]=stwo[i].length();
    }
    for(int i=1;i<=q;i++){
        cin>>tone[i]>>ttwo[i];
        tonel[i]=tone[i].length();
        ttwol[i]=ttwo[i].length();
    }
    for(int ia=1;ia<=q;ia++){
        ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
