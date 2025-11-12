#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a_b, a_f;//b前面和后面有几个a 
}
a[100010][3];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string s1, s2, s3, s4;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s1 >> s2;
		int t = 0;
		while(t ++)
		{
			if(s1[t]  == 'b')
			{
				break;
			}
		}
		a[i][1].a_b = t;
		a[i][1].a_f = s1.size() - a[i][1].a_b - 1;
		t = 0;
		while(t ++)
		{
			if(s2[t] == 'b')
			{
				break;
			}
		}
		a[i][2].a_b = t;
		a[i][2].a_f = s1.size() - a[i][2].a_b - 1;
	}
	int s3b, s3f, s4b, s4f;
	cin >> s3 >> s4;
	int t1 = 0;
	while(t1 ++)
	{
		if(s3[t1]  == 'b')
		{
			break;
		}
	}
	s3b = t1;
	s3f = s3.size() - 1 - s3b;
	t1 = 0;
	while(t1 ++)
	{
		if(s4[t1]  == 'b')
		{
			break;
		}
	}
	s4b = t1;
	s4f = s4.size() - 1 - s4b;
	
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		if((a[i][1].a_b - a[i][2].a_b == s3b - s4b))
			ans ++;
	}
	cout << ans;
}
