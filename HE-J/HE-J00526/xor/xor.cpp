#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int n,m,b,c,ans=0;
	cin>>n>>m;
	int a=n*m;
	cin>>b;
	c=b;
	for(int i=2;i<=a;i++)
	{
		cin>>b;
		if(c<b)
		{
			c=b;
		}else
		 {
			ans++;
		 }
		cout<<c<<endl;
	}
	cout<<ans<<endl;
	cout<<n<<endl;
	return 0;
}
