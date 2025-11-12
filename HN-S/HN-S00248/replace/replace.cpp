#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e6 + 5,M = 2e5 + 5;
long long n,m,siz[M];
string s[M],s2[M];
unsigned long long P = 133,P2[N];
vector<unsigned long long>hsh[N],hsh2[N];
unsigned long long GetHash(long long x,long long y,long long z)
{
	return hsh[z][y] - hsh[z][x] * P2[y - x];
}
unsigned long long GetHash2(long long x,long long y,long long z)
{
	return hsh2[z][y] - hsh2[z][x] * P2[y - x];
}
unsigned long long w3[N],w4[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	P2[0] = 1;
	for(long long i = 1;i <= n;i ++)P2[i] = P2[i - 1] * P;
	for(long long i = 1;i <= n;i ++)
	{
		cin >> s[i] >> s2[i];
		siz[i] = s[i].size();
		s[i] = " " + s[i],s2[i] = " " + s2[i];
		hsh[i].push_back(0),hsh2[i].push_back(0);
		for(long long j = 1;j <= siz[i];j ++)
		{
			hsh[i].push_back(0),hsh2[i].push_back(0);
			hsh[i][j] = hsh[i][j - 1] * P + s[i][j];
			hsh2[i][j] = hsh2[i][j - 1] * P + s2[i][j];
		}
	}
	while(m --)
	{
		string e,f;
		cin >> e >> f;
		long long he = e.size();
		e = " " + e;
		f = " " + f;
		long long l = he,r = 0,ans = 0;
		for(long long i = 1;i <= he;i ++)
			if(e[i] != f[i])
			{
				l = min(l,i);
				r = max(r,i);
			}
		string X = e.substr(l,r - l + 1);
		string Y = f.substr(l,r - l + 1);
		unsigned long long w = 0,w2 = 0;
		for(long long i = 0;i < X.size();i ++)w = w * P + X[i];
		for(long long i = 0;i < Y.size();i ++)w2 = w2 * P + Y[i];
		for(long long i = 1;i <= he;i ++)w3[i] = w3[i - 1] * P + e[i];
		for(long long i = 1;i <= n;i ++)
			for(long long j = 1;j + X.size() - 1 <= siz[i];j ++)
			{
				long long eno = j,ene = j + X.size() - 1;
				if(GetHash(eno - 1,ene,i) == w && GetHash2(eno - 1,ene,i) == w2 && GetHash(0,eno - 1,i) == GetHash2(0,eno - 1,i) && GetHash(ene,siz[i],i) == GetHash2(ene,siz[i],i) && eno <= l && siz[i] - ene + 1 <= he - r + 1)
				{
					//cout << GetHash(0,eno - 1,i) << " " << l - eno << " " << l << " " << (unsigned long long)(w3[l - 1] - w3[l - eno] * P2[eno - 1]) << '\n';
					if(GetHash(0,eno - 1,i) == (unsigned long long)(w3[l - 1] - w3[l - eno] * P2[eno - 1]) && GetHash(ene,siz[i],i) == w3[r + siz[i] - ene] - w3[r] * P2[siz[i] - ene])ans ++;
					// && GetHash(ene,siz[i],i) == w3[r + siz[i] - ene] - w3[r] * P2[siz[i] - ene]
				}
			}
		for(int i = 0;i <= he + 5;i ++)w3[i] = 0;
		cout << ans << '\n';
	}
	return 0;
	//cout << "O UID 303562585";
	//haha not to do this yet
}
//yuan shen qi dong
//shen yuan qi dong

