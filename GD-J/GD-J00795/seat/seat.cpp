#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int n,m,a[110],v,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			v=i;
			break;
		}
	}
	int y=ceil(v*1.0/n);
	cout<<y<<' ';
	if(y%2){
		if(v%n==0) cout<<n;
		else cout<<v%n;
	}else{
		cout<<n-v%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
