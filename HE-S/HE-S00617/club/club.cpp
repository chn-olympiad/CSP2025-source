#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int t,c[4],n,ans = 0;
struct s{
	int x,y,z,mx,cnt;
}a[N];

void dfs(int i,int sum){
	if(i == n+1){
		ans = max(ans,sum);
		return;
	}
	if(c[1]+1 <= n/2){
		sum+=a[i].x;
		c[1]++;
		dfs(i+1,sum);
		c[1]--;
		sum-=a[i].x;
	}
	if(c[2]+1 <= n/2){
		sum+=a[i].z;
		c[2]++;
		dfs(i+1,sum);
		c[2]--;
		sum-=a[i].z;
	}
	if(c[3]+1 <= n/2){
		sum+=a[i].y;
		c[3]++;
		dfs(i+1,sum);
		c[3]--;
		sum-=a[i].y;
	}
}

int ma(int i){
	return max(a[i].x,max(a[i].y,a[i].z));
}

bool cmp(s u,s v){
	return u.mx > v.mx;
}

void fma(int i){
	if(a[i].mx == a[i].x){
		a[i].cnt = 1;
	}else if(a[i].mx == a[i].y){
		a[i].cnt = 2;
	}else{
		a[i].cnt = 3;
	}
}

void gl(int i){
	if(ma(i) == a[i].x)a[i].x = 0;
	else if(ma(i) == a[i].y) a[i].y = -1;
	else a[i].z = -1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		memset(c,0,sizeof(c));
		cin >> n;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].mx = ma(i);
			fma(i);
		}
		if(n <= 20){
			dfs(1,0);
			cout << ans << endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n;i++){
			if(c[a[i].cnt]+1 <= n/2){
				ans+=a[i].mx;
				c[a[i].cnt]++;
				continue;
			}
			gl(i);
			a[i].mx = ma(i);
			fma(i);
			if(c[a[i].cnt]+1 <= n/2){
				ans+=a[i].mx;
				c[a[i].cnt]++;
				continue;
			}
			gl(i);
			a[i].mx = ma(i);
			fma(i);
			if(c[a[i].cnt]+1 <= n/2){
				ans+=a[i].mx;
				c[a[i].cnt]++;
				continue;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
