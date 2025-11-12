#include <bits/stdc++.h>
using namespace std;
int n,m,r;
int a[10009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,greater<>());
	int x=1,i=1,j=1;
	while(x<=n*m){
		if(a[x]==r) break;
		if(i%2==1) j++;
		else j--;
		if(j>n){
			j=n;
			i++;
		}
		if(j<1){
			j=1;
			i++;
		}
		x++;
	}
	cout << i << ' ' << j;
	return 0;
}
