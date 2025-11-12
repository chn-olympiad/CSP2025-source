#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],k,nn,mm,v;
bool cmp(int x,int y){
	if (x>y) return 1;
	else return 0;
}
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++) if (a[i]==k) {k=i; break;}
	v=k/n;
	if (k%n==0){
		mm=v;
		if (v%2==0) nn=1; else nn=n;
	}
	else if (v%2==0){
		mm=v+1;
		nn=k%n;
	}
	else{
		mm=v+1;
		nn=(n+1)-(k%n);
	}
	cout<<mm<<" "<<nn;
	return 0;
}
