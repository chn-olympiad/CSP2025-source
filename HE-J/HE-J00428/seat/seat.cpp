#include<bits/stdc++.h>
using namespace std;
const int N=20;
int s[N][N],a[N*N];
int n,m,r,rk;
int h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) rk=i;
	}
	l=ceil(rk*1.00/n);
	if(l%2==1){
		if(rk%n==0) h=n;
		else h=(rk%n);
	}
	if(l%2==0){
		if(rk%n==0) h=1;
		else h=n-(rk%n)+1;
	}
	cout<<l<<" "<<h<<'\n';
	return 0;
}
/*
6 4
19 2 3 4 5 15 7 8 9 10 11 12 14 13 1 16 17 18 6 20 21 22 23 24
*/
