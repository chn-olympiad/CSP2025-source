#include<bits/stdc++.h>
using namespace std;
int n,m,w,a,cnt=0;
//inline int read()
//{
//	int x=0,q=1;
//	char c=getchar();
//	while(c<'0'||'9'<c)
//	{
//		if(c=='-') q=-1;
//		c=gerchar();
//	}
//	while('0'<=c&&c<='9')
//	{
//		x=(x<<1)+(x<<8)+(c^48);
//		c=getchar();
//	}
//	return x;
// } 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>w;
	int r=n*m;
	for(int i=2;i<=r;i++)
	{
		cin>>a;
		if(a>w) cnt++;
	}
	cnt+=1;
	int l=(cnt/n)+(cnt%n==0? 0:1);
	cout<<l<<' ';
	if(cnt%n==0)
	{
		cout<<(cnt%(2*n)==0? 1:n);
	} 
	else
	{
		if(l%2==1) cout<<cnt%n;
		else cout<<n-cnt%n+1;
	}
	return 0;
}
