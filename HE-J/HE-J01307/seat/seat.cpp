#include<bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin >> n >> m;
	cin >> s;
	a[1]=s;
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			int r,c;
			if(i%n){
				c=i/n+1;
			}
			else{
				c=i/n;
			}
			if(c%2){
				r=i-c*n+n;
			}
			else{
				r=n-(i-(c-1)*n)+1;
			}
			cout << c << " " <<r;
			break;
		}
	}
	return 0;
}
