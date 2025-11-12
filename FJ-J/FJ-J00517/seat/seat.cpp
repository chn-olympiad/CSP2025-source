#include<bits/stdc++.h>
using namespace std;
const int max_n=15;
int ans[max_n][max_n];
int a[max_n*max_n],n,m,dex;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	dex=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==dex){
			dex=n*m-i+1;
		}
	}
	int u=dex%n;
	if(u==0){
		cout << dex/n;
		if((dex/n)%2==0){
			cout << ' ' << 1;
			return 0;
		}
		cout << ' ' << n;
		return 0;
	}else{
		if((dex/n)%2==0){
			cout << dex/n+1 << ' ' << dex%n;
			return 0;
		}else{
			cout << dex/n+1 << ' ' << n-dex%n+1;
			return 0;
		}
	}
	
	return 0;
} 
