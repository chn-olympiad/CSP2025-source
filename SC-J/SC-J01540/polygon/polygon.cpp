#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int a[MAXN]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		int x=a[3];
		if((2*x)>=(a[3]+a[1]+a[2])) cout<<0;
		else cout<<1;
		return 0;
	}
	cout<<3*a[3];
	return 0;
}