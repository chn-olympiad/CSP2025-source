#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N][4],b[4][N],maxn = -1;
int c1 = 0,c2 = 0,c3 = 0,s[N];
//long long cnt = 0;
void dfs(int d,int lv,int n){
//	cnt++;
	if(d > n){
		maxn = max(maxn,lv);
		return;
	}
	if(c1 < n/2){
//		printf("1d:%d\n",d);
		c1++;
		dfs(d+1,lv+a[d][1],n);
		c1--;
	}
	if(c2 < n/2){
//		printf("2d:%d\n",d);
		c2++;
		dfs(d+1,lv+a[d][2],n);
		c2--;
	}
	if(c3 < n/2){
//		printf("3d:%d\n",d);
		c3++;
		dfs(d+1,lv+a[d][3],n);
		c3--;
	}
}
void dfs2(int d,int lv,int n){
//	cnt++;
	if(d > n){
		maxn = max(maxn,lv);
		return;
	}
	if(c1 < n/2){
//		printf("1d:%d\n",d);
		c1++;
		dfs(d+1,lv+a[d][1],n);
		c1--;
	}
	if(c2 < n/2){
//		printf("2d:%d\n",d);
		c2++;
		dfs(d+1,lv+a[d][2],n);
		c2--;
	}

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		maxn = -1;
		int n;
		cin >> n;
		bool flag1 = 1,flag2 = 0;
		for(int i = 1; i <= n ; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[1][i] = a[i][1],b[2][i] = a[i][2],b[3][i] = a[i][3];
			if(a[i][2]!=0&&a[i][3]!=0) flag1 = 0;
			if(a[i][3]!=0) flag2 = 0;
			s[i] = s[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(flag1){
			sort(b[1]+1,b[1]+n+1,greater<int>());
			int sum = 0;
			for(int i = 1; i <= n/2; i ++) sum += b[1][i];
			cout << sum << "\n";
			continue;
		}
		if(flag2){
			dfs2(1,0,n);
			cout << maxn << endl;
			continue;
		}
		dfs(1,0,n);
		cout << maxn << endl;
		
	}
//	cout <<"cnt:"<< cnt;
	return 0;
}

