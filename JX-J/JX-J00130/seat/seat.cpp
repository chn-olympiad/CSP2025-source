#include<bits/stdc++.h>
using namespace std;
int a[110];
int t,n,m,ansn,ansm,s;
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s)
			t=i;
	ansm=(t-1)/n+1;
	if(ansm%2==1) ansn=(t-1)%n+1;
	if(ansm%2==0) ansn=n-(t-1)%n;
	cout<<ansm<<" "<<ansn;
	return 0;
}
