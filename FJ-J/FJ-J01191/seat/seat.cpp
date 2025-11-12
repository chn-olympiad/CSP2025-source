#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,m,cnt,a[maxn];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int tmp = n*m;
	for(int i=1;i<=tmp;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+tmp+1,cmp);
	for(int i=1;i<=tmp;i++){
		if(a[i] == r){
			cnt = i;
			break;
		}
	}
//	cout << cnt << " ";
	int ansx,ansy;
	if(cnt%n != 0){
		ansx = cnt/n+1;
		if(ansx%2 != 0){
			ansy = cnt-(ansx-1)*n;
		}
		else{
			ansy = n-(cnt-(ansx-1)*n-1);
		}
	}
	else{
		ansx = cnt/n;
		if(ansx%2 != 0){
			ansy = n;
		}
		else{
			ansy = 1;
		}
	}
	cout << ansx << " " << ansy;
	return 0;
}

