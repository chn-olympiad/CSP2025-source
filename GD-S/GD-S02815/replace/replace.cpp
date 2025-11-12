#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2;
string s[2][1000000];
bool sure(int i,int m,int p)
{
	for(int j = 0;j < p;j++)
			{
				if(s[0][m][j] != t1[i+j] || s[1][m][j] != t2[i+j])
				{
					return false;
				}
			}
			return true;
}
bool find(int m,int p)
{
	if(s[0][m].size() == p)
	{
		for(int i = 0;i <= t1.size()-p;i++)
		{
			if(sure(i,m,p))
			{
				return true;
			}
		}
	}
	return false;
}
void change()
{
	long long ans = 0;
	for(int i = 1;i <= t1.size();i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(find(j,i))ans++;
		}
	}
	cout << ans <<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int r=1;r <= n;r++)
	{
		cin >> s[0][r] >> s[1][r];
	}
	for(int j = 1;j <= q;j++)
	{
		cin >> t1 >> t2;
		change();
	}
 } 
