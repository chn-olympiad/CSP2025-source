#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("meal.in","r",stdin);
//	freopen("meal.out","w",stdout);
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
	}
	cout<<ans<<endl;
	cout<<n<<endl;
	if(ans>n)
	{
		m=ans-n;
		n=m-1;
		cout<<m-1<<" ";
		cout<<n<<" "<<m;
	}
	return 0;
}
