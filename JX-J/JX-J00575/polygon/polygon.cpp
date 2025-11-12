#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],n,num=0;
void f(int l,int r,int p,int u){
if(l==0&&r>p*2){
    num++;if(num>=998) num%=998;
        return;
}
for(int i=u;i<=n;i++){
if(b[i]==0){
    r+=a[i];
    b[i]=1;if(p<a[i]) p=a[i];
    f(l-1,r,p,i);
    b[i]=0;p=0;r-=a[i];
}
}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
    cin>>a[i];
for(int i=3;i<=n;i++)
    f(i,0,0,1);
    cout<<num%244;
return 0;
}
