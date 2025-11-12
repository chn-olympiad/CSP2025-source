#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,id;
};
node a[1005];
bool cmp(node x,node y){
	return x.x>y.x;
}
int f[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int len = n*m;
	for(int i = 1;i<=len;i++){
		cin >> a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+len+1,cmp);
	for(int i = 1;i<=len;i++){
		if(a[i].id == 1){
			int z;
			if(i%n==0){
				z = i/n;
			}
			else{
				z=i/n+1;
			}
			cout << z<<" ";
			if(z%2==0){
				if(i%n==0){
					cout <<1;
				}
				else{
					cout << n-(i%n)+1;
				}
			}
			else{
				if(i%n==0){
					cout << n;
				}
				else{
					cout << i%n;
				}
			}
		}
	}
	return 0;
}
