#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin >> n >> m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	r=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-i-1;j++){
			if(a[j]<a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	cout << r/n+1 << ' ' ;
	if((r/n+1)%2==1){
		cout << r%n;
	}else{
		cout << n-r%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
