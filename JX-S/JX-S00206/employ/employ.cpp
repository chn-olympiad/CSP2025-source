#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans;
int n,m;
string s;
int c[100010];
int a[100010];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        a[i]=i;
    }
    do{
        int c1[10010];
        for(int i=1;i<=n;i++){
            c1[a[i]]=c[i];
        }
        long long sum=0;
        long long tot=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){
                tot++;
            }else{
                if(c1[i]-tot>0){
                    //cout<<"c:"<<c1[i+1]<<endl;
                    sum++;
                }else{
                    tot++;
                }
            }
        }
        //cout<<tot<<endl;
        //for(int i=1;i<=n;i++){
        //        cout<<c1[i]<<" ";
         //   }
        //    cout<<endl;
        if(sum>=m){
            ans++;
            ans%=mod;
        }
    }while(next_permutation(a+1,a+1+n));
    cout<<ans%mod;
    return 0;
}
// just want get 8pts
// T_T
// csp-s 1= -> 2=/3=
// shit
