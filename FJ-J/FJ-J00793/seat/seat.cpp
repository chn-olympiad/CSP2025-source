#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	const int MAX=n*m;
	int a[105],f;
	for(int i=1;i<=MAX;i++){
		cin >> a[i];
		if(i==1){
			f=a[i];
		}
	}
	sort(a+1,a+1+MAX,cmp);
	for(int i=1;i<=MAX;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	int ansx=f/n+1;
	if(f%n==0) ansx=f/n;
	int ansy;
	if(ansx%2==1){
		ansy=f-(ansx-1)*n;
	}
	else{
		ansy=n-f+(ansx-1)*n+1;
	}
	cout << ansx <<" "<< ansy;
	return 0;
}

