#include<bits/stdc++.h>;
using namespace std;
struct num{
	int sum,x,y,flag;
}a[105];
int n,m,mp[15][15];
bool cmp(num x,num y){
	return x.sum > y.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i].sum;
		a[i].flag = 0;
	}
	a[1].flag = 1;
	sort(a+1,a+n*m+1,cmp);
	int k = 0;
	for(int j = 1;j <= m;j++){
		if(j%2 == 1){
			for(int i = 1;i <= n;i++){
				k++;
				mp[i][j] = a[k].sum;
				a[k].x = i;
				a[k].y = j;
			}
		} else{
			for(int i = n;i >= 1;i--){
				k++;
				mp[i][j] = a[k].sum;
				a[k].x = i;
				a[k].y = j;
			}
		}
	}
	for(int i = 1;i <= n*m;i++){
		if(a[i].flag){
			cout << a[i].y << ' ' << a[i].x;
			return 0;
		}
	}
	return 0;
}
