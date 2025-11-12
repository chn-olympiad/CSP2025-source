#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,b=1,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+n+1,a+1);
	for(int i=1;i<=n*m;i++){
		b++;
		if(b==n){
			b=1;
			c++;
		}
	}
	cout<<b<<c;
	return 0;
}
