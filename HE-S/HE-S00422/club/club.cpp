#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 10;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t > 0)
	{
		t--;
		int n;
		cin>>n;
		int m = n / 2;//每个学院最多有的人数
		bool b[MAXN];//是否已经加入过学院
		int b1 = 0,b2 = 0,b3 = 0;//每个部门加入的人数
		memset(b,0,n); //把b初始化为0
		int a1[MAXN],a2[MAXN],a3[MAXN];//对三个学院的满意度
		int ans1 = 0,ans2 = 0,ans = 0;
		for(int i = 0; i < n; i++)
		{
			//输入满意度
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		for(int i = 0; i < n; i++)
		{
			int t = 0;
			if(b1 < m && b2 < m)
			{
				t = max(a1[i],a2[i]);
				if(a1[i] > a2[i])
				{
					if(b3 >= m)
					{
						t = a1[i];
						b1++;
					}
					else if(a1[i] > a3[i])
					{
						b1++;
						t = a1[i];
					}
					else if(a1[i] <= a3[i])
					{
						b3++;
						t = a3[i];
					}
				}
				else
				{
					if(b3 >= m)
					{
						t = a2[i];
						b2++;
					}
					else if(a2[i] > a3[i])
					{
						b2++;
						t = a2[i];
					}
					else if(a2[i] <= a3[i])
					{
						b3++;
						t = a3[i];
					}
				}
			 }
			else if(b2 < m && b3 < m)
			{
				if(a2[i] > a3[i])
				{
					t = a2[i];
					b2++;
				}
				else
				{
					t = a3[i];
					b3++;
				}
			}
			else if(b1 < m && b3 < m)
			{
				if(a1[i] > a3[i])
				{
					t = a1[i];
					b1++;
				}
				else
				{
					t = a3[i];
					b3++;
				}
			}
			else if(b1 < m)
			{
				t = a1[i];
				b1++;
			}
			else if(b2 < m)
			{
				t = a2[i];
				b2++;
			}
			else if(b3 < m)
			{
				t = a3[i];
				b3++;
			}
			ans1 += t;
		}
		b1 = 0;
		b2 = 0;
		b3 = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			int t = 0;
			if(b1 < m && b2 < m)
			{
				t = max(a1[i],a2[i]);
				if(a1[i] > a2[i])
				{
					if(b3 >= m)
					{
						t = a1[i];
						b1++;
					}
					else if(a1[i] > a3[i])
					{
						b1++;
						t = a1[i];
					}
					else if(a1[i] <= a3[i])
					{
						b3++;
						t = a3[i];
					}
				}
				else
				{
					if(b3 >= m)
					{
						t = a2[i];
						b2++;
					}
					else if(a2[i] > a3[i])
					{
						b2++;
						t = a2[i];
					}
					else if(a2[i] <= a3[i])
					{
						b3++;
						t = a3[i];
					}
				}
			 }
			else if(b2 < m && b3 < m)
			{
				if(a2[i] > a3[i])
				{
					t = a2[i];
					b2++;
				}
				else
				{
					t = a3[i];
					b3++;
				}
			}
			else if(b1 < m && b3 < m)
			{
				if(a1[i] > a3[i])
				{
					t = a1[i];
					b1++;
				}
				else
				{
					t = a3[i];
					b3++;
				}
			}
			else if(b1 < m)
			{
				t = a1[i];
				b1++;
			}
			else if(b2 < m)
			{
				t = a2[i];
				b2++;
			}
			else if(b3 < m)
			{
				t = a3[i];
				b3++;
			}
			ans2 += t;
		}
		ans = max(ans1,ans2);
		cout<<ans<<endl;
	}
	return 0;
}
