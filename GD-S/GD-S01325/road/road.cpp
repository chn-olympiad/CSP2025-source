#include<bits/stdc++.h>
using namespace std;
int T,t;
int ans[5],n,sum;
struct node{
	int maxx,minn;
	int sum;
	int mid;
	int i,midi;
	int x[5];
}a[100010],mid[100010];
bool cmp(node x,node y){
//	if(x.maxx == y.maxx){
//		return x.mid > y.mid; 
//	}
	return x.mid > y.mid;
}
int main(){
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		t = 0;
		sum = 0;
		memset(ans,0,sizeof(ans));
		cin >> n;
		for(int i = 1;i <= n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			a[i].x[1] = x;
			a[i].x[2] = y;
			a[i].x[3] = z;
			a[i].maxx = max(max(x,y),z);
			a[i].minn = min(min(x,y),z);
			a[i].sum = x + y + z;
			a[i].mid = a[i].sum - a[i].maxx - a[i].minn;
			mid[i].mid = a[i].mid;
			mid[i].i = i;
			if(x >= y && x >= z){
				a[i].i = 1;
				if(y >= z){
					a[i].midi = 2;
				}else{
					a[i].midi = 3;
				}
			}else if(y >= x && y >= z){
				a[i].i = 2;
				if(x >= z){
					a[i].midi = 1;
				}else{
					a[i].midi = 3;
				}
			}else if(z >= x && z >= y){
				a[i].i = 3;
				if(x >= y){
					a[i].midi = 1;
				}else{
					a[i].midi = 2;
				}
			}
		}
//		sort(a + 1,a + 1 + n,cmp);
		for(int i = 1;i <= n;i++){
			sum += a[i].x[a[i].i];
			ans[a[i].i]++;
//			cout << a[i].i << endl;
		}
		sort(a + 1,a + 1 + n,cmp);
		int j = 1;
		for(int i = 1;i <= 3;i++){
			if(ans[i] > (n / 2)){
				for(int k = 1;k <= (ans[i] - (n / 2));k++){
					sum = sum - a[mid[j].i].x[i];
					sum = sum + mid[j].mid;
					j++;
				}
			}
		}
//		cout << endl;
		cout << sum << endl;
	}
	return 0;
}
