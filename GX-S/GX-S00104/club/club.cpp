#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct human{
	int a,b,c;
	int ma;
}a[100005];
int T,n;
bool pd1(int k,int a1,int b1,int c1){
	if (k == 1){
		if (a1 >= n/2) return false;
	}else if (k == 2){
		if (b1 >= n/2) return false;
	}else if (k == 3){
		if (c1 >= n/2) return false;
	}
	return true;
}
bool cmp1(human x,human y){
	return x.ma > y.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--){
		long long ans = 0;
		struct dp{
			int data=0;
			int a1=0,b1=0,c1=0;
		}f[100005][4];
		memset(a,0,sizeof(a));
		cin >> n;
		if (n == 200){

		}
		for (int i = 1;i<=n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].ma = max(a[i].a,max(a[i].b,a[i].c));
		}
		sort(a+1,a+1+n,cmp1);
		// f[1][1].data = a[1].a;
		// f[1][1].a1 = 1;
		// f[1][2].data = a[1].b;
		// f[1][2].b1 = 1;
		// f[1][3].data = a[1].c;
		// f[1][3].c1 = 1;
		for (int i = 1;i<=n;i++){
			int t1[5] = {-1,a[i].a,a[i].b,a[i].c};
			for (int j = 1;j<=3;j++){ // history abc
				// cout << "i=" << i << " " << "j=" << j << endl;
				for (int k = 1;k<=3;k++){ // now abc
					int choose = f[i-1][j].data + t1[k];
					// cout << "f[i][k] = " << f[i][k].data << " ";
					// cout << "k=" << k << " " << "choose=" << choose << " pd=" << pd1(k,f[i-1][j].a1,f[i-1][j].b1,f[i-1][j].c1) << " ";
					// cout << f[i-1][j].a1 << " " << f[i-1][j].b1 << " " << f[i-1][j].c1 << endl;
					if (f[i][k].data < choose && pd1(k,f[i-1][j].a1,f[i-1][j].b1,f[i-1][j].c1)){
						f[i][k].data = f[i-1][j].data + t1[k];
						if (k == 1){
							f[i][k].a1 = f[i-1][j].a1 + 1;
							f[i][k].b1 = f[i-1][j].b1;
							f[i][k].c1 = f[i-1][j].c1;
						}
						else if (k == 2){
							f[i][k].a1 = f[i-1][j].a1;
							f[i][k].b1 = f[i-1][j].b1 + 1;
							f[i][k].c1 = f[i-1][j].c1;
						}
						else if (k == 3){
							f[i][k].a1 = f[i-1][j].a1;
							f[i][k].b1 = f[i-1][j].b1;
							f[i][k].c1 = f[i-1][j].c1 + 1;
						}
					}
					// f[i][k].data = max(f[i][k].data,f[i-1][j].data + t1[k]);
				}
			}
		}
		cout << max(f[n][1].data,max(f[n][2].data,f[n][3].data)) << endl;
	}
}