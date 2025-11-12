#include <bits/stdc++.h>
using namespace std;
int a[110];
int r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	for (int i=1;i<=m;i++){
		if(i%2==0){
			for (int j=n;j>=1;j--){
				p++;
				if(a[p]==r){
					cout << i << " " << j;
				}
			}
		}
		else{
			for (int j=1;j<=n;j++){
				p++;
				if(a[p]==r){
					cout << i << " " << j;
				}
			}
		}
	}
	return 0;
}
