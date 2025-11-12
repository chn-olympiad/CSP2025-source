#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	if(R<=n){
		cout << 1 <<' ' << R;
		return 0;
	}
	if(R<=2*n){
		cout << 2 << ' ' << n-(R-n)+1;
		return 0;
	}
	int x=1,y=1;
	int cnt=1;
	while(y<=m/2){
		for(int i=1;i<=2*n;i++){
			if(i<n && x<n){
				cnt++;
				x++;
			}else if(i==n && x==n){
				cnt++;
				y++;
			}else if(i>n){
				cnt++;
				x--;
			}
			if(cnt==R)break;
		}
		if(cnt==R)break;
		cnt++;
		y++;
		if(cnt==R)break;
	}
	cout << y << ' ' << x;
	return 0;
}
