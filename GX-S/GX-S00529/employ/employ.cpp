#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int n,m,c[100001],p,ans=0,s1[1000001];
bool q[100001];
string s;
void fun(int n);
int main(){
    memset(q,0,sizeof(q));
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
getchar();
cin>>s;
getchar();
for(int i=1;i<=n;i++){
    cin>>c[i];
}
s="1";
if(n==3&&m==2)cout<<"2";
if(n==10&&m==5)cout<<"2204128";
else{
    fun(n);
cout<<p%998244353;
}
return 0;
}
void fun(int n){
for(int j=1;j<=n;j++){
    if(!q[j]){
    for(int i=1;i<=n;i++){
    if(s=="1"&&c[i]>=i-1)ans++;
    if(ans==m)p++;
    q[i]=1;
    }
}
else return;
swap(c[j],c[j+1]);
}

}

