#include <bits/stdc++.h>
using namespace std;
int n,mod = 998244353;
long long r;
int l[5010];
void f(int c,int i,int x,bool fl){
	if(i > n) return ;
	int maxx = l[i];
	if(fl){
		c += l[i];
		x ++;
	}
	if(x > 2 && c > maxx * 2){
		r ++;
	}
	f(c,i + 1,x,1);
	f(c,i + 1,x,0);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1,t;i <= n;i ++){
		cin >> l[i];
	}
	sort(l + 1,l + n + 1);
	f(0,1,0,1);
	f(0,1,0,0);
	if(r >= mod) r %= mod;
	cout << r << endl;
	return 0;
}
