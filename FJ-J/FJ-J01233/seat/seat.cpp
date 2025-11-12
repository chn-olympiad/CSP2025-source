#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[N];
int n,m;
int a1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	int num=0;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		num++;
		if(a[i]==a1) break;
	}
	int l=(num-1)/n+1;
	int h;
	if(l%2==0) h=n-(num%(m+1));
	else h=num-(l-1)*n;
	cout<<l<<' '<<h;
	return 0;
}
