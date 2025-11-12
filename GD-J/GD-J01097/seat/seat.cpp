#include <bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> n >> m; 
	int a[110];
	int b[n][m];
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int cj = a[1];
	int h;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-1;j++){
		    if(a[j+1]>a[j]){
		    	h = a[j+1];
		    	a[j+1] = a[j];
		    	a[j] = h;
			}
	    }
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			cj = i;
		}
	}
	if(cj%n==0){
		if(cj/n%2==0){
			cout  << cj/n << " " << 1;
		}else{
			cout << cj/n << " " << n;
		}
	}
	if(cj%n!=0){
		if(cj/n%2==0){
			cout << cj/n+1 << " " << cj%n;
		}else{
			cout << cj/n+1 << " " << n-(cj%n)+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
