#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
struct stu
{
	int gr,id;
} a[maxn*maxn];
int n,m;
int mp[maxn][maxn]; 
bool cmp(stu x,stu y)
{
	if(x.gr != y.gr) return x.gr > y.gr;
	return x.id < y.id;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i].gr,a[i].id = i;
	sort(a+1,a+n*m+1,cmp);
	int now = 0;
	for(int j = 1;j <= m;j++)
	{
		if(j & 1)
			for(int i = 1;i <= n;i++) 
			{
				mp[i][j] = a[++now].id;
				if(mp[i][j] == 1)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		else
			for(int i = n;i >= 1;i--) 
			{
				mp[i][j] = a[++now].id;
				if(mp[i][j] == 1)
				{
					cout << j << " " << i;
					return 0;
				}
			}
	}
	return 0;
	
}

