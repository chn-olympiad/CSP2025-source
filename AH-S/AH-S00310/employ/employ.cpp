#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long sun=1;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m,c[100001000],cnt=0;
int e[16]={0,1,2,3,4,5,6,7,8,9,10};
string s[550];
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>s[i];

}
for(int i=1;i<=n;i++){
    cin>>c[i];
    if(!c[i]) cnt++;
}
    if(n<=10){
        do{
            sun=cnt=0;
            for(int i=0;i<n;i++){
                if(c[i]<=cnt){
                    cnt++;
                }else if(s[i]=='0'){
                cnt++;
                }else{
                sun++;
                }
                if(sun>=m){
                    t++;
                }
            }
        }while(next-permutation(e,e+n));
        cout<<t;
    }
return 0;
}
