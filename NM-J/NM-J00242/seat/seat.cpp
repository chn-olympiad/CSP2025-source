#include<bits/stdc++.h>
using namespace std;
int a[1000],e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	int b=a[1],c=0,d=0;
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		e++;
		if(a[i]==b){
			c=e;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			d++;
			if(d==c&&i%2!=0){
				cout <<i<<' '<<j;
				return 0;
			}else if(d==c&&i%2==0){
				cout <<i<<' '<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}
