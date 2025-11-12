#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
int a[N][4];
int f[4];
int abc(int p){
	int maxx=0;
	//p表示第p个数 
	if (p>n){
		return 0;
	}
	int maxn;
	for (int i=1;i<=3;i++){
		if (f[i]+1>(n/2)){
			continue;
		}
		f[i]++;
		maxn = a[p][i]+abc(p+1); 
		f[i]--;
		if (maxn>maxx){
			maxx = maxn;
		}
	}
	return maxx;
}

int abc1(int p){
	int maxx=0;
	//p表示第p个数 
	if (p>n){
		return 0;
	}
	int maxn;
	for (int i=1;i<=2;i++){
		if (f[i]+1>(n/2)){
			continue;
		}
		f[i]++;
		maxn = a[p][i]+abc1(p+1); 
		f[i]--;
		if (maxn>maxx){
			maxx = maxn;
		}
	}
	return maxx;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		f[3] = 0,f[1] = 0,f[2] = 0;
		int sss=0,vv=0;
		for (int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] == 0&&a[i][3] == 0) sss++;
			if (a[i][3]==0) vv++; 
		}
		if (vv==n){
			cout << abc1(1) << endl;
			continue;
		}
		if (sss == n){
			int ssss[N];
			for (int i=1;i<=n;i++){
				ssss[i] = a[i][2];
			}
			sort(ssss+1,ssss+n+1);
			int ssssss=0;
			for (int i=(n/2)+1;i<=n;i++){
				ssssss+=ssss[i];
			}
			cout << ssssss << endl;
			continue;
		}
		cout << abc(1) << endl;
	}
	return 0;
} 
