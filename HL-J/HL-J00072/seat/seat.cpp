#include<bits/stdc++.h>
using namespace std;
int mp[11][11];
const int N=1e3;
int a[N];
int n,m;
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	if(n==1){
		for(int i=1;i<=m;i++){
			if(a[i]>a[1]){
				cnt++;
			}
		}
		cout << cnt+1 <<" " << 1 << endl;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>a[1]){
				cnt++;
			}
		}
		cout << 1 <<" " << cnt+1;
	}
	if(n==2&&m==2){
		for(int i=1;i<=4;i++){
			if(a[i]>a[1]){
				cnt++;
			}
		}
		if(cnt+1==1){
			cout <<1 <<" " << 1;
			return 0;
		}
		if(cnt+1==2){
			cout << 1 <<" "<< 2;
			return 0;
		}
		if(cnt+1==3){
			cout << 2 <<" " << 2;
			return 0;
		}
		else cout << 2 <<" " << 1;
	}
	if(n==2&&m>2){
		for(int i=1;i<=n*m;i++){
			if(a[i]>a[1]){
				cnt++;
			}
		}
		int x=cnt+1;
		if(x%4==0){
			cout << x/2 <<" "<< 1;
		}
		if(x%4==1){
			cout << x/2+1 <<" " << 1;
		}
		if(x%4==2){
			cout << x/2+1 <<" " << 2;
		}
		if(x%4==3){
			cout << x/2 <<" "<< 2;
		}
	}
	if(n>2&&m==2){
		for(int i=1;i<=n*m;i++){
			if(a[i]>a[1]){
				cnt++;
			}
		}
		int y=cnt+1;
		if(y<=n){
			cout << 1 <<" " << y;	
		}
		else{
			cout << 2 <<" " << 2*n-y;
		}
	}

}

