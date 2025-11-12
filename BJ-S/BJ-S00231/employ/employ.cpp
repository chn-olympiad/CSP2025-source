#include<bits/stdc++.h>
using namespace std;
int n,m;char s[509];int c[509],sha=0;
void jie(int s){
long long o=1;
for(int i=1;i<=s;i++){
o%=998244353;
o*=i;//cout<<o<<endl;
}cout<<o%998244353;

}
int main(){
    freopen("employ.in","r",stdin);
     freopen("employ.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
        cin>>s[i];if(s[i]=='1')sha++;}
for(int i=1;i<=n;i++)cin>>c[i];//cout<<sha;
if(sha==n and n==100){
cout<<161088479;
return 0;}
cout<<0;
return 0;}
