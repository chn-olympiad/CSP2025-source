#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,x=1,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)    cin >> a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(x/2*2==2)    y--;
		else    y++;
		if(y==n+1)    y=n,x++;
		if(y==0)    y=1,x++;
		if(a[i]==b){
			cout << x << " " << y;
			return 0;
		}
	}
	return 0;
}

