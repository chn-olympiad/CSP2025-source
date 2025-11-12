#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],num,w,b,an;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
		if(a[i]==num)
		{
			b=i;
			break;
		}
	if(b==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	if(b%n!=0)
	{
		cout<<b/n+1<<" ";
		an=b/n+1;
	}
	else
	{
		cout<<b/n<<" ";
		an=b/n;
	}
	w=b%n;
	if(w==0)w=n;
	if(an%2==1)
		cout<<w;
	if(an%2==0)
		cout<<n-w+1;
	return 0;
}
