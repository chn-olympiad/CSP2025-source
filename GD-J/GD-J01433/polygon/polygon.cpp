#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050];
long long cnt;
long long sum;
int vi = 0,ri = 0;
int maxn = 0;

bool cmp(int a,int b){
	return a < b;
}

void f(int v,int step,int m,int v2){
	if(v2 >= n-ri) return;
	if(v > n){
		v2++;
		sum = a[vi];
		maxn = 0;
		step = 1;
		f(vi+v2,step+1,m,v2);
	}
	if(step > m){
		if(sum > maxn*2){
			cnt++;
			maxn = 0;
			sum -= a[v];
			step--;
		}
	}
	sum += a[v];
	maxn = a[v];
	f(v+1,step+1,m,v2);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			vi = j; ri = i;
			f(j,1,i,1);
		}
	}
	cout << cnt;
	return 0;
}
