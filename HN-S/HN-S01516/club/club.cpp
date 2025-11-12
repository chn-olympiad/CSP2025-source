#include<bits/stdc++.h>
using namespace std;
int t;
int a[100009][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin >> t;
	for(int r = 0; r < t; r++){
		int n;
		cin >> n;
		int g = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i][2] >> a[i][1] >> a[i][0];
		}
		int d = n%3;
		int b =0;
		while(true){
			int s=0, x;
			for(int i = 0; i < n; i++){
				if(s<a[i][0]){
					x = i;
					s = a[i][0];
					g += s;
				}
			}
			a[x][0] = 0;
			a[x][1] = 0;
			a[x][2] = 0;
			if(d == 1 && n - d <= 2){
				break;
			} 
			int m=0;
			for(int i = 0; i < n; i++){
				if(m<a[i][1]){
					x = i;
					m = a[i][1];
					g += m;
				}
			}
			a[x][0] = 0;
			a[x][1] = 0;
			a[x][2] = 0;
			if(d == 2 && n - d <= 2){
				break;
			} 
			int u=0;
			for(int i = 0; i < n; i++){
				if(u<a[i][1]){
					x = i;
					u = a[i][1];
					g += u;
				}
			}
			a[x][0] = 0;
			a[x][1] = 0;
			a[x][2] = 0;
			if(d == 1 && n - d <= 2){
				break;
			}
			d = d + 3;
		}
		cout << g << " ";
	}
	return 0;
}
