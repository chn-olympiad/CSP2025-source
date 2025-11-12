#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std; 
ll t,n,ans,f[100005];
struct stu
{
	ll to_c,to_b,to_a;
} s[100005];
stu min_a,min_b,min_c;
vector<stu> a,b,c;
/*stu a[100005],b[100005],c[100005];*/
bool cmp_a(stu x,stu y)
{
	return x.to_a > y.to_a;
}
bool cmp_b(stu x,stu y)
{
	return x.to_b > y.to_b;
}
bool cmp_c(stu x,stu y)
{
	return x.to_c > y.to_c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	min_a.to_a = 0x3f3f3f;
	min_a.to_b = 0x3f3f3f;
	min_a.to_c = 0x3f3f3f;
	min_b.to_a = 0x3f3f3f;
	min_b.to_b = 0x3f3f3f;
	min_b.to_c = 0x3f3f3f;
	min_c.to_a = 0x3f3f3f;
	min_c.to_b = 0x3f3f3f;
	min_c.to_c = 0x3f3f3f;
	for(int l = 1 ; l <= t ; l++)
	{
		cin >> n;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> s[j].to_a >> s[j].to_b >> s[j].to_c;
		}
		for(int i = 1 ; i <= n ; i++)
		{
		if(max(max(s[i].to_a,s[i].to_b),s[i].to_c) == s[i].to_a)
		{
			if(a.size() >= n / 2)
			{
				stu d = min_a;
				sort(a.begin(),a.end(),cmp_a);
				if(/*d.to_a < s[i].to_a && */(d.to_b + s[i].to_a > d.to_a || d.to_c + s[i].to_a > d.to_a))
				{
					a.pop_back();
					a.push_back(s[i]);
					if(d.to_b > d.to_c)
					{
						if(b.size() < n / 2)
						{
							b.push_back(d);
							f[i] = f[i - 1] + d.to_b - d.to_a + s[i].to_a;
							if(d.to_b < min_b.to_b)
							{
								min_b = d;
							}
						}
						else
						{
							c.push_back(d);
							f[i] = f[i - 1] + d.to_c - d.to_a + s[i].to_a;
							if(d.to_c < min_c.to_c)
							{
								min_c = d;
							}
						}
					}
					else
					{
						if(c.size() < n / 2)
						{
							c.push_back(d);
							f[i] = f[i - 1] + d.to_c - d.to_a + s[i].to_a;
							if(d.to_c < min_c.to_c)
							{
								min_c = d;
							}
						}
						else
						{
							b.push_back(d);
							f[i] = f[i - 1] + d.to_b - d.to_a + s[i].to_a;
							if(d.to_b < min_b.to_b)
							{
								min_b = d;
							}
						}
					}
				}
				else
				{
					if(s[i].to_b > s[i].to_c)
					{
						if(b.size() < n / 2)
						{
							b.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_b;
							if(s[i].to_b < min_b.to_b)
							{
								min_b = s[i];
							}
						}
						else
						{
							c.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_c;
							if(s[i].to_c < min_c.to_c)
							{
								min_c = s[i];
							}
						}
					}
					else
					{
						if(c.size() < n / 2)
						{
							c.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_c;
							if(s[i].to_c < min_c.to_c)
							{
								min_c = s[i];
							}
						}
						else
						{
							b.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_b;
							if(s[i].to_b < min_b.to_b)
							{
								min_b = s[i];
							}
						}
					}
				}
			}
			else
			{
				if(s[i].to_a < min_a.to_a)
				{
					min_a = s[i];
				}
				f[i] = f[i - 1] + s[i].to_a;
				a.push_back(s[i]);
			}
		}
		else if(max(max(s[i].to_a,s[i].to_b),s[i].to_c) == s[i].to_b)
		{
			if(b.size() >= n / 2)
			{
				stu d = min_b;
				sort(b.begin(),b.end(),cmp_b);
				if(/*d.to_b < s[i].to_b && */(d.to_a + s[i].to_b > d.to_b || d.to_c + s[i].to_b > d.to_b))
				{
					b.pop_back();
					b.push_back(s[i]);
					if(d.to_a > d.to_c)
					{
						if(a.size() < n / 2)
						{
							a.push_back(d);
							f[i] = f[i - 1] + d.to_a - d.to_b + s[i].to_b;
							if(d.to_a < min_a.to_a)
							{
								min_a = d;
							}
						}
						else
						{
							c.push_back(d);
							f[i] = f[i - 1] + d.to_c - d.to_b + s[i].to_b;
							if(d.to_c < min_c.to_c)
							{
								min_c = d;
							}
						}
					}
					else
					{
						if(c.size() < n / 2)
						{
							c.push_back(d);
							f[i] = f[i - 1] + d.to_c - d.to_b + s[i].to_b;
							if(d.to_c < min_c.to_c)
							{
								min_c = d;
							}
						}
						else
						{
							a.push_back(d);
							f[i] = f[i - 1] + d.to_a - d.to_b + s[i].to_b;
							if(d.to_a < min_a.to_a)
							{
								min_a = d;
							}
						}
					}
				}
				else
				{
					if(s[i].to_a > s[i].to_c)
					{
						if(a.size() < n / 2)
						{
							a.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_a;
							if(s[i].to_a < min_a.to_a)
							{
								min_a = s[i];
							}
						}
						else
						{
							c.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_c;
							if(s[i].to_c < min_c.to_c)
							{
								min_c = s[i];
							}
						}
					}
					else
					{
						if(c.size() < n / 2)
						{
							c.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_c;
							if(s[i].to_c < min_c.to_c)
							{
								min_c = s[i];
							}
						}
						else
						{
							a.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_a;
							if(s[i].to_a < min_a.to_a)
							{
								min_a = s[i];
							}
						}
					}
				}
			}
			else
			{
				if(s[i].to_b < min_b.to_b)
				{
					min_b = s[i];
				}
				f[i] = f[i - 1] + s[i].to_b;
				b.push_back(s[i]);
			}
		}
		else
		{
			if(c.size() >= n / 2)
			{
				stu d = min_c;
				sort(c.begin(),c.end(),cmp_c);
				if(/*d.to_c < s[i].to_c && */(d.to_a + s[i].to_c > d.to_c || d.to_b + s[i].to_c > d.to_c))
				{
					c.pop_back();
					c.push_back(s[i]);
					if(d.to_a > d.to_b)
					{
						if(a.size() < n / 2)
						{
							a.push_back(d);
							f[i] = f[i - 1] + d.to_a - d.to_c + s[i].to_c;
							if(d.to_a < min_a.to_a)
							{
								min_a = d;
							}
						}
						else
						{
							b.push_back(d);
							f[i] = f[i - 1] + d.to_b - d.to_c + s[i].to_c;
							if(d.to_b < min_b.to_b)
							{
								min_b = d;
							}
						}
					}
					else
					{
						if(b.size() < n / 2)
						{
							b.push_back(d);
							f[i] = f[i - 1] + d.to_b - d.to_c + s[i].to_c;
							if(d.to_b < min_b.to_b)
							{
								min_b = d;
							}
						}
						else
						{
							a.push_back(d);
							f[i] = f[i - 1] + d.to_a - d.to_c + s[i].to_c;
							if(d.to_a < min_a.to_a)
							{
								min_a = d;
							}
						}
					}
				}
				else
				{
					if(s[i].to_a > s[i].to_b)
					{
						if(a.size() < n / 2)
						{
							a.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_a;
							if(s[i].to_a < min_a.to_a)
							{
								min_a = s[i];
							}
						else
						{
							b.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_b;
							if(s[i].to_b < min_b.to_b)
							{
								min_b = s[i];
							}
						}
					}
					else
					{
						if(b.size() < n / 2)
						{
							b.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_b;
							if(s[i].to_b < min_b.to_b)
							{
								min_b = s[i];
							}
						}
						else
						{
							a.push_back(s[i]);
							f[i] = f[i - 1] + s[i].to_a;
							if(s[i].to_a < min_a.to_a)
							{
								min_a = s[i];
							}
						}
					}
				}
			}
			} 
			else
			{
				if(s[i].to_c < min_b.to_c)
				{
					min_c = s[i];
				}
				f[i] = f[i - 1] + s[i].to_c;
				c.push_back(s[i]);
			}
		}
	}
	//cout << a.size() << " "<< b.size() << " "<< c.size() << "\n";
	cout << f[n] << endl;
	memset(f,0,sizeof(f));
	a.clear();
	b.clear();
	c.clear();
	}
	/*
	for(int i = 1 ; i <= t ; i++)
	{
		cin >> n;
		ll cnt_a = 0,cnt_b = 0,cnt_c = 0,ans = 0;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> s[j].to_a >> s[j].to_b >> s[j].to_c;
			if(max(max(s[j].to_a,s[j].to_b),s[j].to_c) == s[j].to_a)
			{
				a[++cnt_a] = s[j];
			}
			else if(max(max(s[j].to_a,s[j].to_b),s[j].to_c) == s[j].to_b)
			{
				b[++cnt_b] = s[j];
			}
			else
			{
				c[++cnt_c] = s[j];
			}
		}
		sort(a + 1,a + cnt_a + 1,cmp_a);
		int stat_a;
		for(int l = 1 ; l <= cnt_a ; l++)
		{
			if(l <= n / 2)
			{
				ans += a[l].to_a;
			}
			else
			{
				stat_a = l;
				cnt_a -= (l - 1);
				break;
			}
		}
		while(cnt_a > 0)
		{
			cnt_a--;
			if(a[stat_a].to_b > a[stat_a].to_c)
			{	
				b[++cnt_b] = a[stat_a++];
			}
			else
			{
				c[++cnt_c] = a[stat_a++];
			}
		}
		sort(b + 1,b + cnt_b + 1,cmp_b);
		int stat_b;
		for(int l = 1 ; l <= cnt_b ; l++)
		{
			if(l <= n / 2)
			{
				ans += b[l].to_b;
			}
			else
			{
				stat_b = l;
				cnt_b -= (l - 1);
				break;
			}
		} 
		while(cnt_b > 0)
		{
			cnt_b--;
			c[++cnt_c] = b[stat_b++];
		}
		sort(c + 1,c + cnt_c + 1,cmp_c);
		for(int l = 1 ; l <= cnt_c ; l++)
		{
			if(l <= n / 2)
			{
				ans += c[l].to_c;
			}
			else
			{
				break;
			}
		} 
		cout << ans;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	*/
	return 0;
}
