#include<bits/stdc++.h>
using namespace std;
int x=0,y=0,point,wei=0,a[105],n,m,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	num=n*m;
	for(int i=1;i<=num;i++)cin >> a[i];
	point=a[1];
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		wei++;
		if(point==a[i])break;
	}
	for(int i=1;i<=m;i++){
		wei -= n;
		x++;
		if(wei<=0)break;
	}
	if(x%2==1)y=n+wei;
	else y=1-wei;
	cout << x << ' ' << y;
	return 0;
}
