#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n,a[N][3],ans;
int ve[3][N],l[3];
int val[N];
int b[10];
/*
struct node
{
	int id,w;
	int operator < (const node a) const
	{
		return w > a.w;
	}
};
priority_queue<node> q[3];
*/
void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}

void work(int k)
{
	for(int i = 0; i < 3; i++)
		b[i] = i;
	
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++)
			if(a[k][b[i]] < a[k][b[j]])
				swap(b[i],b[j]);
}

int cmp(int x,int y)
{
	return val[x] > val[y];
}

void work1(int k)
{
	//cout << l[k] << "\n";
	//cout << k << "\n";
	sort(ve[k] + 1,ve[k] + l[k] + 1,cmp);
	for(int i = 1; i <= l[k] - (n / 2); i++)
		ans += val[ve[k][i]];
		//cout << val[ve[k][i]] << "\n";
}

void solve()
{
	
	cin >> n; 
	ans = l[0] = l[1] = l[2] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 3; j++)
			cin >> a[i][j];
		work(i);
		//cout << b[0] << "\n";
		ve[b[0]][++l[b[0]]] = i;
		ans += a[i][b[0]];
		//cout << a[i][b[0]] << "\n";
		val[i] = max(a[i][b[1]] - a[i][b[0]],
		a[i][b[2]] - a[i][b[0]]);
		//cout << val[i] << "\n";
	}
	
	if(l[0] > (n / 2))
		work1(0);
	else if(l[1] > (n / 2))
		work1(1);
	else if(l[2] > (n / 2))
		work1(2);
	
	cout << ans << "\n";
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
		solve();
} 
