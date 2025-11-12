#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long m,s,h,cnt;
void dfs(long long x,long long m,long long s,long long h){
	
//	cout << x << ' ' << s << endl;
	
	if(s >= 3 && h > m * 2){
		cnt ++;
		cnt = cnt % 998244353;
	}
	
	
	for(int i = x + 1;i <= n;i ++){
		if(a[i] > m){
			dfs(i,a[i],s + 1,h + a[i]);
		}
		else{
			dfs(i,m,s + 1,h + a[i]);
		}
	}
	
	return ;
}
int fl = 1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] != 1) fl = 0;
	}
	if(fl == 1){
		for(int i = 3;i <= n;i ++){
			long long xc = 1;
			for(int j = 1;j <= i;j ++){
				xc *= n - j + 1;
				xc /= j;
				xc = xc % 998244353;
			}
//			cout << xc << endl;
			cnt += xc;
		}
		cout << cnt ;
		return 0;
	} 
	for(int i = 1;i <= n;i ++){
		m = a[i];
		s = 1;
		h = a[i];
		dfs(i,m,s,h);
	}
	cout << cnt;
	return 0;
}
