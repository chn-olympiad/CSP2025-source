#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
int n,m,a[N],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>a[1]) p++;
	}
	int l=p/m,h=p%m;
	if((l+1)%2==1) cout << l+1 << ' ' << h+1;
	else cout << l+1 << ' ' << m-h;
}
