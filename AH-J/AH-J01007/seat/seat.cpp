#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m,zre=1,cxpd;
cin>>n>>m;
cin>>cxpd;
for(int i=1;i<n*m;i++)
{
	int x;
 cin>>x;
 if(x>cxpd) zre++; 
}
int lp=(zre-1)/m+1,zp=(zre-1)%m+1;
cout<<lp<<' ';
if(lp%2==1) cout<<zp;
else cout<<m-zp+1;
return 0;
}
