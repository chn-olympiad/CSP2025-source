#include <bits/stdc++.h>
using namespace std;
struct df{
	int zh;
	int cd1;
	int cd2;
	int cd3;
	int r;
};
bool zs(df a,df b){
	return a.zh > b.zh;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int c;
		cin >> c;
		df a[c+1][4];
		for(int j = 1;j <= c;j++){
			df b[4];
			for(int z = 1;z <= 3;z++){
				int sw;
				cin >> sw;
				b[z].zh = sw;
				b[z].cd1 = 0;
				b[z].cd2 = 0;
				b[z].cd3 = 0;
				b[z].r = z;
				if(z == 1){
					b[z].cd1 = 1;
				}else if(z == 2){
					b[z].cd2 = 1;
				}else if(z == 3){
					b[z].cd3 = 1;
				}
			}
			sort(b+1,b+4,zs);
			for(int z = 1;z <= 3;z++){
				a[j][z].zh = b[z].zh;
				a[j][z].cd1 = b[z].cd1;
				a[j][z].cd2 = b[z].cd2;
				a[j][z].cd3 = b[z].cd3;
				a[j][z].r = b[z].r;
			}
		}
		for(int j = 2;j <= c;j++){
			for(int z = 1;z <= 3;z++){
				for(int zx = 1;zx <= 3;zx++){
					if(a[j][z].r == 1 && (a[j-1][zx].cd1 + 1) <= c/2){
						a[j][z].cd1 = a[j-1][zx].cd1 + 1;
						a[j][z].cd2 = a[j-1][zx].cd2;
						a[j][z].cd3 = a[j-1][zx].cd3;
						a[j][z].zh = a[j-1][zx].zh + a[j][z].zh;
						break;
					}else if(a[j][z].r == 2 && (a[j-1][zx].cd2 + 1) <= c/2){
						a[j][z].cd1 = a[j-1][zx].cd1;
						a[j][z].cd3 = a[j-1][zx].cd3;
						a[j][z].cd2 = a[j-1][zx].cd2 + 1;
						a[j][z].zh = a[j-1][zx].zh + a[j][z].zh;
						break;
					}else if(a[j][z].r == 3 && (a[j-1][zx].cd3 + 1) <= c/2){
						a[j][z].cd1 = a[j-1][zx].cd1;
						a[j][z].cd2 = a[j-1][zx].cd2;
						a[j][z].cd3 = a[j-1][zx].cd3 + 1;
						a[j][z].zh = a[j-1][zx].zh + a[j][z].zh;
						break;
					}
				}
			}
		}
		int o = -1;
		for(int j = 1;j <= 3;j++){
			if(a[c][i].zh > o){
				o = a[c][i].zh;
			}
		}
		cout << o << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
