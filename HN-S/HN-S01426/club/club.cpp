#include<bits/stdc++.h> 
using namespace std;
int n;
int main(){
	freopen("club.in",'r',stdin);
	freopen("club.out",'w',stdout);
	cin >> n;
	long long x[n] = {};
	for(int i = 0;i < n;i++){
		int y;
		cin >> y;
		int a[y],b[y],c[y];
		for(int j = 0;j < y;j++){
			cin >> a[j] >> b[j] >> c[j];
		}
		for(int j = 0;j < y;j++){
			x[i] += max(a[j],max(b[j],c[j]));
		}
	}
	for(int i = 0;i < n;i++)cout << x[i] << endl;
	return 0;
}
