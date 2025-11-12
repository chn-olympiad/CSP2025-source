#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],num,t,L,H;
bool cmp(int x,int y)
{	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t)
		{	num=i;
			break;
		}
	if(num%n==0)	L=num/n;
	else	L=num/n+1;
	if(L%2==1)	H=num-n*(L-1);
	else	H=n-(num-n*(L-1))+1;
	cout<<L<<" "<<H;
	return 0;
}
