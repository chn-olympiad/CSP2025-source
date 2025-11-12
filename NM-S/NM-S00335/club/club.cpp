#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int a1;
	int a2;
	int a3;
}student[10005];
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n;
	int ans[10];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int club1=0,club2=0,club3=0;
		for(int j=1;j<=n;j++)
		{
			cin>>student[j].a1>>student[j].a2>>student[j].a3;
		}
		for(int j=1;j<=n;j++)
		{
			if(student[j].a1 >= student[j].a2 && student[j].a1 >= student[j].a3 && club1 < n/2)
			{
				ans[i]+=student[j].a1;
				club1++;
				continue;
			}
			if(student[j].a1 >= student[j].a2 && student[j].a1 >= student[j].a3 && club1 >= n/2)
			{
				if(student[j].a2>student[j].a3 && club2 < n/2)
				{
					ans[i]+=student[j].a2;
					continue;
				}
				if(student[j].a3>student[j].a2 && club3 < n/2)
				{
					ans[i]+=student[j].a3;
					continue;
				}
				else
				{
					ans[1]+=max(student[j].a2,student[j].a3);
				}	
			}
			
			if(student[j].a2 >= student[j].a3 && student[j].a2 >= student[j].a1 && club2 >= n/2)
			{
				if(student[j].a1>student[j].a3 && club1 < n/2)
				{
					ans[i]+=student[j].a1;
					continue;
				}
				if(student[j].a3>student[j].a1 && club3 < n/2)
				{
					ans[i]+=student[j].a3;
					continue;
				}
				else
				{
					ans[1]+=max(student[j].a1,student[j].a3);
				}	
			}
			
			if(student[j].a2 >= student[j].a1 && student[j].a2 >= student[j].a3 && club2 < n/2)
			{
				ans[i]+=student[j].a2;
				club2++;
				continue;
			}
			
			if(student[j].a3 >= student[j].a1 && student[j].a3 >= student[j].a2 && club3 >= n/2)
			{
				if(student[j].a1>student[j].a2 && club1 < n/2)
				{
					ans[i]+=student[j].a1;
					continue;
				}
				if(student[j].a2>student[j].a1 && club2 < n/2)
				{
					ans[i]+=student[j].a2;
					continue;
				}
				else
				{
					ans[1]+=max(student[j].a2,student[j].a1);
				}	
			}
			
			if(student[j].a3 >= student[j].a1 && student[j].a3 >= student[j].a2 && club3 < n/2)
			{
				ans[i]+=student[j].a3;
				club3++;
				continue;
			}
			if(club1 >= n/2 && club2>=n/2 && club3<=n/2)
			{
				ans[i]+=student[j].a3;
				continue;
			}
			if(club1 >= n/2 && club2<=n/2 && club3>=n/2)
			{
				ans[i]+=student[j].a2;
				continue;
			}
			if(club1 <= n/2 && club2>=n/2 && club3>=n/2)
			{
				ans[i]+=student[j].a1;
				continue;
			}
				
			if(club1 >= n/2 && club2<=n/2 && club3<=n/2)
			{
				ans[i]+=max(student[j].a2,student[j].a3);
				continue;
			}
			if(club1 <= n/2 && club2>=n/2 && club3<=n/2)
			{
				ans[i]+=max(student[j].a1,student[j].a3);
				continue;
			}
			if(club1 <= n/2 && club2<=n/2 && club3>=n/2)
			{
				ans[i]+=max(student[j].a2,student[j].a1);
				continue;
			}
				
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
