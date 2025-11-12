#include <bits/stdc++.h>
using namespace std;

ifstream fin("employ.in",ios_base::in);
ofstream fout("employ.out",ios_base::out);

#define maxN 1005
#define mod 998244353

int n,m;
string c;
int a[maxN];
void solve1()
{
	int ans[maxN];
	long long res = 0;
	for(int i = 1; i <= n; i++)
		ans[i] = i;
	do
	{
		/*cout << "Check new\n";
		for(int i = 1; i <= n; i++)
			cout << ans[i] <<' ';
		cout << '\n';*/
		int ref = 0,acc = 0;
		bool flag = 0;
		for(int i = 1; i <= n; i++)
		{
			if(ref >= a[ans[i]])
				ref++;
			else if(c[i - 1] == '0')
				ref++;
			else
				acc++;
			if(acc >= m)
			{
				flag = 1;
				break;
			}
			//cout << acc << ' ' << ref <<' ' << a[ans[i]] << ' ' << c[i-1] << '\n';
		}
		if(flag)
			res = (res + 1) % mod;
	} while(next_permutation(ans+1,ans+n+1));
	fout << res;
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	fin.tie(0);
	fout.tie(0);
	fin >> n >> m;
	fin >> c;
	for(int i = 1; i <= n; i++)
		fin >> a[i];
	if(n <= 10)
		solve1();
	else
		cout << 0;
	fin.tie(0);
	fout.tie(0);
	return 0;
}
