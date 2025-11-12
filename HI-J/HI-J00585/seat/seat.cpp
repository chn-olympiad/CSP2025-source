#include <bits/stdc++.h>
using namespace std;
bool dd (int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for (int i = 1;i <= n*m;i ++){
		cin>>a[i];
	}
	int t = a[1];
	sort(a+1,a+n*m,dd);
	if (a[1] == t){
		cout<<1<<" "<<1;
		return 0; 
	}
	int u;
	for (int i = 1;i <= n*m;i++){
		if (a[i] == t){
			u = i;
			break;
		}
	}
	cout<< u/n+1<<" ";
	if (u%n%2 != 0){
		cout<< u%n;
		return 0;
	} 
	else{
		cout<< n - u%n;
		return 0;
	}
	return 0;
}
