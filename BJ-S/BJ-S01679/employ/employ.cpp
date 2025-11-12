#include <bits/stdc++.h>
using namespace std;
const int N = 514;
const long long MOD=998244353;
long long n,m,c[N],ans,a[N];
char s[N];
bool flagg=true;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i]=i;
        cin>>s[i];
        if(s[i]!='1') flagg=false;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=10){
        //int ccc=0;
        do{
            //ccc++;
            int cnty=0,cntn=0;
            for(int i=1;i<=n;i++){
                //cout<<a[i]<<' ';
                if(cntn>=c[a[i]]){cntn++;continue;}
                if(s[i]=='1') cnty++;
                if(s[i]=='0') cntn++;
            }
            //cout<<'\n';
            //cout<<cntn<<' '<<cnty<<"\n";
            if(cnty>=m) ans=(ans+1)%MOD;
        }while(next_permutation(a+1,a+n+1));
        //cout<<ccc<<"  11111111\n\n";
        return cout<<ans,0;
    }
    if(flagg){
        ans=1;
        for(long long i=1;i<=n+1;i++){
            ans=((ans%MOD)*(i%MOD))%MOD;
        }
        return cout<<ans%MOD,0;
    }

    return 0;
}
