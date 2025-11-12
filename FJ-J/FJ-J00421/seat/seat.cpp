#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int a1=a[1];
	sort(a,a+n*m);
	for (int i=n*m;i>=1;i--){
		if(a1==a[i]){
			a1=n*m-i+1;
			break;
		}
	}
	int l;
	int h;
	if(a1/m%2==0){
		l=a1/m;
		h=n-(a1%m);
	}
	else{
		l=a1/m+1;
		h=a1%m+1;
	}
	cout << l << ' ' << h;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
