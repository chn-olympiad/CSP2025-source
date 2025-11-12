#include<bits/stdc++.h>
#define _all(i,a,b) for(int i = a; i <= b; i++)
#define __all(i,a,b) for(int i = a; i < b; i++)
#define r_all(i,a,b) for(int i = a; i >= b;i--)
#define vt vector<int>
#define v2 vector<vt>
#define vl vector<LL>
using namespace std;
using LL = long long;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,k;
	cin>>n>>k;
	vt a(n+1),d(n+1,1e9);
	v2 f(n+1,vt(n+1));
	_all(i,1,n) cin>>a[i],f[i][i] = a[i];
	_all(i,1,n) _all(j,i,n){
		f[i][j] = f[i][j-1] ^ a[j];
		if(f[i][j] == k) d[i] = min(d[i],j - i);
	} 
	int ans = 1;
	_all(i,1,n){
		int j = i + d[i] + 1,cnt = 1;
		if(d[i] == 1e9) continue;
		while(j <= n){
			if(d[j] != 1e9) cnt ++,j += (d[j] + 1);
			else j ++ ;
		}
		ans = max(ans,cnt);
	}
	return printf("%d",ans),0; //freopen!
}

//n^2做法