#include <bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int b[5001];
int k;
void df(int u,int z,int h,int zd,int shang){
	if(u == z + 1){
		if(h > (zd*2)){
			k = k + 1;
			k = k % 998244353;
		}
	}else{
		for(int i = 1;i <= n;i++){
			if(b[i] == 1 && i > shang){
				b[i] = 0;
				int h1 = h + a[i];
				int zd1 = zd;
				if(a[i] > zd1){
					zd1 = a[i];
				}
				int shang1 = i;
				df(u+1,z,h1,zd1,shang1);
				b[i] = 1;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = 1;
	}
	k = 0;
	for(int i = 1;i <= n;i++){
		df(1,i,0,0,0);
	}
	cout << k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
