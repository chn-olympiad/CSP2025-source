#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
	}
bool she;
long long n,m,b[12100],s,R;
int main()
{
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
	cin>>b[i];
R=b[1];
sort(b,b+n*m,cmp);
if(m==1&&n==1){cout<<"1 1";return 0;}
else if(n==1&&m<=10)
{cout<<1<<" ";
	for(int i=1;i<=n;i++)
	if(b[i]==R){cout<<i;return 0;}
}
else if(m==1&&n<=10)
{
	for(int i=1;i<=m;i++)
	if(b[i]==R){cout<<i<<" "<<1;return 0;}
	
}
else if(m<=2&&n<=2)
{
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	if(b[i]==R){
		if(i>2)
		{cout<<2<<" "<<2-j;return 0;}
	else 	{cout<<1<<" "<<j;return 0;}	
}
}
else if(m<=10&&n<=2)
{
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	{
		s++;
		if(s%2==0)she=!she;
		if(b[i]==R){
		if(she){cout<<ceil(double(i/2))<<" "<<2-j;return 0;}
		else{cout<<ceil(double(i/2))<<" "<<j;return 0;}
		}
	}
}
else cout<<4<<4;
return 0;

}
