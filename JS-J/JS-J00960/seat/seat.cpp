#include <bits/stdc++.h>
using namespace std;
int b[110];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++)
	{
		cin>>b[i];
	}
	int cnt=1,ans=b[1];
	sort(b+1,b+h+1,cmp);
	for(int i=1;i<=h;i++)
	{
		if(b[i]>ans)
		{
			cnt++;
		}
	}
	if(((cnt+n-1)/n)%2==1)
	{
		if(cnt%n!=0)
			cout<<(cnt+n-1)/n<<" "<<cnt%n<<endl;
		else
			cout<<(cnt+n-1)/n<<" "<<n<<endl;
	}
	else if(((cnt+n-1)/n)%2==0)
	{
		cout<<(cnt+n-1)/n<<" "<<m-((cnt+m-1)%m)<<endl;
	}
	return 0;
}
