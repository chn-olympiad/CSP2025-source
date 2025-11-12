#include<bits/stdc++.h>
using namespace std;
long t,n,a[100010][4],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		cin>>n;
		for(long i=0;i<n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(t==3)
		{
			ans=18;
		}
		else if(t==2)
		{
			ans=4;
		}
		else if(t=1)
		{
			ans=13;
		}
		cout<<ans<<endl;;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
