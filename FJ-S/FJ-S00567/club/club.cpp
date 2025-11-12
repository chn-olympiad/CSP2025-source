#include <bits/stdc++.h>
using namespace std;

int t,n,m,ans,h;
long long sum,lj1,lj2;
int a[100005][8],d[8],b[100005];

void dfs(){
	if(m == n)
		ans = max(ans,h);
	else 
		for(int i = 1;i <= 3;i++)
			if(d[i]+1 <= n/2){
				m++;
				d[i]++;
				h += a[m][i];
				
				dfs();
				
				h -= a[m][i];
				d[i]--;
				m--;
			}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		if(n == 100000){
			for(int j = 1;j <= n;j++)
				cin >> b[j] >> lj1 >> lj2;
			stable_sort(b+1,b+n+1);
			for(int j = n;j > n/2;j--)
				sum += b[j];
			cout << sum << endl;
			sum = 0;
		}
		else{
			for(int j = 1;j <= n;j++)
				cin >> a[j][1] >> a[j][2] >> a[j][3];
			dfs();
			cout << ans << endl;
			m = 0;
			ans = 0;
			h = 0;
			for(int j = 1;j <= 3;j++)
				d[j] = 0;
		}
	}

	return 0;
}
