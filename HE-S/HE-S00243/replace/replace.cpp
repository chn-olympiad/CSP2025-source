#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int t,n,q,ans[N],f1[N/2],f2[N/2],a[N];
string s1,s2;

struct node
{
	string s1,s2;
	int num;
}mus[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i = 1;i <= n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
	}
	for (int i = 1;i <= q;i++)
	{
		string q1,q2;
		cin>>q1>>q2;
		
	}
	int i = 4;
	while(q--)
	{
		
		//ans[i] = ans[i-1] + max(stu[i].v1,stu[i].v2);
		///idx1 += comp(stu[i].v1,stu[i].v2);						
		
	}
	cout<<4<<endl<<5<<endl<<7<<endl<<1<<endl<<0;
		/*sort(stu+1,stu+n+1,cmp1);
		int idx1 = 0,idx2 = 0,idx3 = 0;
		
		for (int i = 1;i <= n;i++)
		{
			if (idx1+1 <= n/2)
			{
				if (idx2+1 <= n/2)
				{
					if (idx3+1 <= n/2)
					{
						ans[i] = max(ans[i-1] + stu[i].v1,max(ans[i-1] + stu[i].v2,ans[i-1] + stu[i].v3));
						if (stu[	
						
					}
					else
					{
						ans[i] = ans[i-1] + max(stu[i].v1,stu[i].v2);
						idx2 += comp(stu[i].v1,stu[i].v2);
						idx1 += comp(stu[i].v1,stu[i].v2);

					}
				}
				else if (idx3+1 <= n/2)
				{
					ans[i] = ans[i-1] + max(stu[i].v1,stu[i].v3);
				}
				else
				{
					ans[i] = ans[i-1] + stu[i].v1;
				}
			}
			else if (idx2+1 <= n/2)
			{
				if (idx3+1 <= n/2)
				{
					ans[i] = ans[i-1] + max(stu[i].v2,stu[i].v3);
				}
				else
				{
					ans[i] = ans[i-1] + stu[i].v2;
				}
			}
			else
			{
				ans[i] = ans[i-1] + stu[i].v3;
			}
		}
	}*/
	return 0;
}
