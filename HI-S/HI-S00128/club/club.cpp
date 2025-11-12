#include <bits/stdc++.h>
using namespace std;
struct club
{
	int member;
	int satisfy_1;
	int satisfy_2;
	int satisfy_3;
}sum[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	club a;int t;cin>>t;
	while(t--)
	{
		int n,c=0;cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>sum[i].satisfy_1>>sum[i].satisfy_2>>sum[i].satisfy_3;
			sum[i].member=i;
		}	
		int f1=0,f2=0,f3=0;
		for(int i=1;i<=n;i++)
		{
			int m=max(sum[i].satisfy_1,max(sum[i].satisfy_2,sum[i].satisfy_3));
			if(m==sum[i].satisfy_1&&f1<=n/2)
			{
				c+=sum[i].satisfy_1;
				f1++;
			}
			else if(m==sum[i].satisfy_2&&f2<=n/2)
			{
				c+=sum[i].satisfy_2;
				f2++;
			}
			else if(m==sum[i].satisfy_3&&f3<=n/2)
			{
				c+=sum[i].satisfy_3;
				f3++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
