#include<iostream>
#include<algorithm>

using namespace std;

long long MOD = 998244353;

int n,m;
long long ans = 1;
int pi,zn = 0;
int p[501][2];
string s;


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
		
	int c[n + 1];
	for(int i = 1;i <= n;i ++ )
	{
		cin >> c[i];
	}
	for(int i = 0;i < n;i ++ )
	{
		if(s[i] == '1')
		{
			p[pi ++ ][1] = zn;
		}
		else if(s[i] == '0')
		{
			zn ++ ;
		}
	}
	
	for(int i = 1;i <= n;i ++ )
	{
		for(int j = pi-1;j >= 0;j -- )
		{
			if(c[i] > p[j][1])
			{
				p[j][0] ++ ;
				break;
			}
		}
	}
	
	for(int i = 0;i < m; i++)
	{
		ans *= p[i][0];
	}
	cout << ans%MOD << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
