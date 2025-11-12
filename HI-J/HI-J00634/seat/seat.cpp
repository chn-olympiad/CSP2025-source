#include <bits/stdc++.h>
using namespace std;
int n,m,s,b,c;
int a[105],d[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
    s = a[1];
	sort(a+1,a+ n * m +1,cmp);
	int z = 1;
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			for(int j = 1;j <= m;j++){
				d[z] = a[i * n + j];
				z++;
			}
		}
		else{
			for(int j = m;j >= 1;j--){
				d[z] = a[i * n + j];
				z++;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 1;j <= m;j++){
			if(d[i * n + j] == s){
		    	cout << i+1 << " " << j;
		    	return 0; 
		    }
		}
	}
	return 0;
}
