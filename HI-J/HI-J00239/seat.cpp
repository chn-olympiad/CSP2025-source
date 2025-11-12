#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cyy,wz;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int cnt=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[1]<a[i]) cnt++;
	}
	if(cnt==1)
	{
		cout<<"1 1"<<endl;
		return 0;
	}
	else if(cnt%n==0)
	{
		cyy=cnt/n;
		if(cyy%2==1)
		{
			cout<<cyy<<" "<<n<<endl;
			return 0;
		}
		else
		{
			cout<<cyy<<" "<<1<<endl;
			return 0;
		}
	}
	else
	{
		cyy=cnt/n+1;
		if(cyy%2==1)
		{
			cout<<cyy<<" "<<cnt%n<<endl;
			return 0;
		}
		else
		{
			cout<<cyy<<" "<<n-cnt%n+1<<endl;
			return 0;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
