#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
const int N = 1e3+10;
int a[N];
int x,y,z,h;
bool f(int a){
	return a%2 == 0;
}
bool cmp(int a,int b){
	return a > b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	z = a[1]; 
	sort(a+1,a+n*m+1,cmp); 
	for(int i = 1; i <= n*m; i++){
		if(z == a[i]){
			h = i;
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		sum += m;
		if(sum >= h){
			if(f(i)){
				int k = h%m;
				int xx = 1;
				for(int j = m; j >= 1; j--){
					if(xx == k){
						y = j;
					}
					xx++;
				}
				x = i;
				cout << x << " " << y;
				return 0;
			}else{
				x = i;
				if(h%m == 0){
					y = m;
				} else{
					y = h%m;
				}
				cout << x << " "<< y;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
