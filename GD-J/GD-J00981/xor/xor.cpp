#include<bits/stdc++.h> 
using namespace std;
int n, k, a[500005], z, ans=0, zz=-1;
int yh(int x, int y){
	
	string xx, yy, z;
	int s = 0;
	while(x>0){
		xx = char(x%2+'0')+xx;
		x/=2;
	}
	while(y>0){
		yy = char(y%2+'0')+yy;
		y/=2;
	}
	while(xx.size()>yy.size()){
		yy = '0' + yy;
	}while(xx.size()<yy.size()){
		xx = '0' + xx;
	}
	int l = yy.size();
	for(int i = 0; i < l; i++){
		z += char('0'+(yy[i]!=xx[i]));
	}
	for(int i = 0; i < z.size(); i++){
		s = s*2+z[i]-'0';
	}
	return s;
}
void xr(int x, int y){
	if(y>=n||x>=n)return;
	if(x==y&&x==zz){
		xr(x+1, y+1);
		return;
	}
	if(x==y){
		z = a[x];
	}else{
		z = yh(z, a[y]);
	}
	if(z==k){
		ans++;
		if(y<=zz)ans--;
		zz = y;
		xr(x+1, x+1);
	}else if(y==zz-1){
		xr(x+1, x+1);
	}else{
		xr(x, y+1);
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++)cin >> a[i];
	xr(0,0);
	cout << ans;
	return 0;
}
