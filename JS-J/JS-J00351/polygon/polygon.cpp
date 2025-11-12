#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans = 0;
bool gon(int ln,int mxn,int tt){
	return ln >= 3 && mxn * 2 < tt;
}
void gonc(int ln,int mxn,int tt,int ep){
	if(gon(ln,mxn,tt)){
		cout << ln << " " << mxn << " " << tt << endl;
		ans++;
	}
	for(int i = ep + 1;i < n;i++){
		gonc(ln + 1,a[i],tt + a[i],i);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	for(int i = 0;i < n;i++){
		gonc(1,a[i],a[i],i);
	}
	cout << ans << endl;
	return 0;
}
