#include<iostream>
#include<cmath>
using namespace std;
int n,m,c,a[201],t,s,ans1,ans2;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++) cin>>a[i];
c=a[1];
for(int i=1;i<=n*m;i++){
    for(int j=1;j<=n*m;j++){
        if(a[i]>a[j]){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
}
for(int i=1;i<=n*m;i++){
    if(c==a[i]) s=i;
}
if(s%m==0) ans1=s/m;
else ans1=s/m+1;
ans2=s%n;
cout<<ans1<<' ';
if(s%m!=0 && ans1%2==0) cout<<(n-ans2+1);
else if(s%m==0) cout<<n;
else cout<<ans2;
fclose(stdin);
fclose(stdout);
return 0;
}
