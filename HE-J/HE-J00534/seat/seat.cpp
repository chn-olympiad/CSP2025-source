#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cnt;
int b;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int a1=a[1];
	if(n==1&&m==1){
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1) b=i;
	}
	
	int c=(n*m-b)+1;
	if(c<=n){
		cout << 1 << ' ' << c << endl;
		return 0;
	}
	else{
		if(c%n==0){
			cout << n << " " << c/n << endl;
			return 0;
		}
		else{
			if((c/n+1)%2==0) cout << c/n+1 << ' ' << c%n+1 << endl;
			else cout << c/n+1 << ' ' << c%n << endl;
			return 0;
		}
	}
	return 0;
} 
