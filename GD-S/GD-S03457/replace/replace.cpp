#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
constexpr int ofs = 5000000;
void rdi(int& x)
{
	char c;
	while((c = getchar_unlocked()) > '9' || c < '0');
	x = c - '0';
	while((c = getchar_unlocked()) >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
	}
}
void rds(string& s)
{
	char c;
	while((c = getchar_unlocked()) > 'z' || c < 'a');
	s = {c};
	while((c = getchar_unlocked()) >= 'a' && c <= 'z')
	{
		s += c;
	}
}
int n, q, ans[200005], mxsz = 0;
string s[200005][2], t[200005][2];
int ps[200005][2], pt[200005][2];
struct CHG {
	int x, y, z;
	CHG(int X, int Y, int Z) {x = X, y = Y, z = Z;}
};
struct QR {
	int id, x, y, z;
	QR(int I, int X, int Y, int Z) {id = I, x = X, y = Y, z = Z;}
};
vector<CHG> v[10000005];
vector<QR> qr[10000005];
bool cmpc(CHG x, CHG y)
{
	return x.x < y.x;
}
bool cmpq(QR x, QR y)
{
	return x.x < y.x;
}
int bitt[5000005];
void add(int x, int ad)
{
	while(x <= mxsz)
	{
		bitt[x] += ad, x += (x & -x);
	}
}
int qry(int x)
{
	int ret = 0;
	while(x)
	{
		ret += bitt[x], x -= (x & -x);
	}
	return ret;
}
bool subB = 1;
int chk_spe(string& s)
{
	int n = s.size();
	int ret = -1;
	for(int i=0;i<n;i++)
	{
		if(s[i] != 'a' && s[i] != 'b')
		{
			return -1;
		}
		if(s[i] == 'b')
		{
			if(ret != -1)
			{
				return -1;
			}
			ret = i;
		}
	}
	if(ret == -1)
	{
		return -1;
	}
	return ret + 1;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	rdi(n); rdi(q);
	for(int i=1;i<=n;i++)
	{
		rds(s[i][0]); rds(s[i][1]);
		mxsz = max(mxsz, (int)s[i][0].size());
		mxsz = max(mxsz, (int)s[i][1].size());
		subB &= ((ps[i][0] = chk_spe(s[i][0])) != -1);
		subB &= ((ps[i][1] = chk_spe(s[i][1])) != -1);
	}
	for(int i=1;i<=q;i++)
	{
		rds(t[i][0]); rds(t[i][1]);
		mxsz = max(mxsz, (int)t[i][0].size());
		mxsz = max(mxsz, (int)t[i][1].size());
		subB &= ((pt[i][0] = chk_spe(t[i][0])) != -1);
		subB &= ((pt[i][1] = chk_spe(t[i][1])) != -1);
	}
	if(subB)
	{
		for(int i=1;i<=n;i++)
		{
			v[ps[i][0] - ps[i][1] + ofs].push_back(CHG(s[i][0].size(), ps[i][0], ps[i][1]));
		}
		for(int i=1;i<=q;i++)
		{
			qr[pt[i][0] - pt[i][1] + ofs].push_back(QR(i, t[i][0].size(), pt[i][0], pt[i][1]));
		}
		for(int i=-mxsz+ofs;i<=mxsz+ofs;i++)
		{
			if(qr[i].size())
			{
				sort(v[i].begin(), v[i].end(), cmpc);
				sort(qr[i].begin(), qr[i].end(), cmpq);
				int cur = 0;
				for(int j=0;j<(int)qr[i].size();j++)
				{
					while(cur < (int)v[i].size() && v[i][cur].x <= qr[i][j].x)
					{
						add(v[i][cur].y, 1);
						cur++;
					}
					ans[qr[i][j].id] = qry(qr[i][j].y);
				}
				for(int j=0;j<cur;j++)
				{
					add(v[i][j].y, -1);
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			cout << ans[i] << endl;
		}
		return 0;
	}
	
	return 0;
}
