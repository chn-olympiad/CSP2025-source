#include<bits/stdc++.h>
using namespace std;
int ans,i,a[1001],j,m,n,k;
bool cmp(int a,int b) 
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k = a[1];
	for(i = 2;i <= m * n;i++){
		 cin>>a[i];
	}
	sort(a + 1,a + m * n + 1,cmp);
	for(i = 1;i <= m * n;i++){
		if(a[i] == k)
		{
			j = i;
		}
	}
	cout<<j / n + 1<<' ';
	if((j / n) % 2 == 0)
	{
		if(j % n == 0)
		{
			cout<<n<<endl;
		}
		else
		{
			cout<<j % n<<endl;
		}
	}
	else
	{
		if((j % n) == 0)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<n - j % n + 1<<endl;
	}
	}
}
