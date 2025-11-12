#include<bits/stdc++.h>
using namespace std;
string a[500001],sm;
string too(int x){
    string s="";
    while(x!=0){
        if(x%2==0) s="0"+s;
        else s="1"+s;
        x/=2;
    }
    while(s.size()!=9) s="0"+s;
    return s;
}
string ch(string a,string b){
    string s="";
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]) s=s+"0";
        else s=s+"1";
    }
}
bool pr(int l,int r){
    string zax=a[l];
    if(l==r){
        if(zax==sm) return 1;
        return 0;
    }
    for(int i=l+1;i<=r;i++){
        string now="";
        for(int j=1;j<=zax.size();j++){
            if(zax[j]==a[i][j]) now=now+"0";
            else now=now+"1";
        }
        zax=now;
    }

}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    sm=too(m);
    int fmax=-1,fsum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1) fsum++;
        fmax=max(fmax,x);
        a[i]=too(x);
    }
    if(fmax==1){
        cout<<fsum<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(pr(i,j)){
                i=j+1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
