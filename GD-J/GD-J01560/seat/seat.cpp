#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],x,t,b[100][100],v = 0,f = 0;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	x = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == x){
			t = i;
		}
	}
	for(int i = 1;i <= m;i++){
		if(i%2 == 1){
			for(int j = 1;j <= n;j++){
				v++;
				if(v == t){
					cout << i << " " << j;
					f = 1;
					break;
				}
			}
		}else{
			for(int j = n;j >= 1;j--){
				v++;
				if(v == t){
					cout << i << " " << j;
					f = 1;
					break;
				}
			} 	
		}
		if(f)break;
	}
	return 0;
} 
