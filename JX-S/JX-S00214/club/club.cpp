#include<bits/stdc++.h>
using namespace std;

int t,n,k;
int ans;

struct Vector3
{
	int index;
	int x,y,z;
	int maxva,maxj;
	int midva,midj;
	int cha;
} a[100010];

bool operator <(Vector3 v1,Vector3 v2)
{
	return v1.index < v2.index;
}

//from big to small
bool cmp(Vector3 v1,Vector3 v2)
{
	return v1.maxva > v2.maxva;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		ans = 0;
		
		priority_queue< pair<int,Vector3> > q1;
		priority_queue< pair<int,Vector3> > q2;
		priority_queue< pair<int,Vector3> > q3;
		
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].index = i;
			if(a[i].x >= a[i].y && a[i].x >= a[i].z)
			{
				a[i].maxva = a[i].x;
				a[i].maxj = 0;
				if(a[i].y >= a[i].z)
				{
					a[i].midj = 1;
					a[i].midva = a[i].y;
				}
				else
				{
					a[i].midj = 2;
					a[i].midva = a[i].z;
				}
				a[i].cha = a[i].maxva - a[i].midva;
			}
			else if(a[i].y >= a[i].x && a[i].y >= a[i].z)
			{
				a[i].maxva = a[i].y;
				a[i].maxj = 1;
				if(a[i].x >= a[i].z)
				{
					a[i].midj = 0;
					a[i].midva = a[i].x;
				}
				else
				{
					a[i].midj = 2;
					a[i].midva = a[i].z;
				}
				a[i].cha = a[i].maxva - a[i].midva;
			}
			else if(a[i].z >= a[i].y && a[i].z >= a[i].x)
			{
				a[i].maxva = a[i].z;
				a[i].maxj = 2;
				if(a[i].y >= a[i].x)
				{
					a[i].midj = 1;
					a[i].midva = a[i].y;
				}
				else
				{
					a[i].midj = 0;
					a[i].midva = a[i].x;
				}
				a[i].cha = a[i].maxva - a[i].midva;
			}
		}
		sort(a + 1,a + n + 1,cmp);
		for(int i = 1;i <= n;i++)
		{
			if(a[i].maxj == 0)
			{				
				if(q1.size() < n*0.5)
				{
					q1.push(make_pair(-a[i].cha,a[i]));
					ans += a[i].maxva;
				}
				else
				{
					Vector3 rec = q1.top().second;
					if(a[i].cha > rec.cha)
					{
						q1.pop();
						ans -= rec.cha;
						ans += a[i].maxva;
						q1.push(make_pair(-a[i].cha,a[i]));
						if(rec.midj == 1)
						{
							q2.push(make_pair(-rec.cha,rec));
						}
						else if(rec.midj == 2)
						{
							q3.push(make_pair(-rec.cha,rec));
						}
					}
					else
					{
						ans += a[i].midva;
						if(a[i].midj == 1)
						{
							q2.push(make_pair(-a[i].cha,a[i]));
						}
						else if(a[i].midj == 2)
						{
							q3.push(make_pair(-a[i].cha,a[i]));
						}
					}
				}
			}
			if(a[i].maxj == 1)
			{
				if((q2.size()) < n*0.5)
				{
					q2.push(make_pair(-a[i].cha,a[i]));
					ans += a[i].maxva;
				}
				else
				{
					Vector3 rec = q2.top().second;
					if(a[i].cha > rec.cha)
					{
						q2.pop();
						ans -= rec.cha;
						ans += a[i].maxva;
						q2.push(make_pair(-a[i].cha,a[i]));
						if(rec.midj == 0)
						{
							q1.push(make_pair(-rec.cha,rec));
						}
						else if(rec.midj == 2)
						{
							q3.push(make_pair(-rec.cha,rec));
						}
					}
					else
					{
						ans += a[i].midva;
						if(a[i].midj == 0)
						{
							q1.push(make_pair(-a[i].cha,a[i]));
						}
						else if(a[i].midj == 2)
						{
							q3.push(make_pair(-a[i].cha,a[i]));
						}
					}
				}
			}
			if(a[i].maxj == 2)
			{
				if(q3.size() < n*0.5)
				{
					ans += a[i].maxva;
					q3.push(make_pair(-a[i].cha,a[i]));
				}
				else
				{
					Vector3 rec = q3.top().second;
					if(a[i].cha > rec.cha)
					{
						q3.pop();
						ans -= rec.cha;
						ans += a[i].maxva;
						q3.push(make_pair(-a[i].cha,a[i]));
						if(rec.midj == 1)
						{
							q2.push(make_pair(-rec.cha,rec));
						}
						else if(rec.midj == 0)
						{
							q1.push(make_pair(-rec.cha,rec));
						}
					}
					else
					{
						ans += a[i].midva;
						if(a[i].midj == 1)
						{
							q2.push(make_pair(-a[i].cha,a[i]));
						}
						else if(a[i].midj == 0)
						{
							q1.push(make_pair(-a[i].cha,a[i]));
						}
					}
				}
			}
			
		}
		cout << ans << endl;
		
	}
	return 0;
}
