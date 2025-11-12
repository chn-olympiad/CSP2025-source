#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,n,m,h,r,kkk,l,m1,n1,z[999];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;n1=n;
for(int i=1;i<=n*m;i++){
    cin>>a;
    z[i]=a;
}
b=z[1];
sort(z+1,z+1+n*m);
for(int j=1;j<=n*m;j++){if(j%n==1)m1+=1;
    if(z[j]==b){

    if(m1%2==0)r=j-(j/n*n);
    else r=n-(j-j/n*n)+1;
    }
}
c=m1;
cout<<r<<" "<<c;
fclose(stdin);
fclose(stdout);
return 0;
}
