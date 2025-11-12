#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N*N];
int n,m;
int x;
bool cmp(int a,int b){
	return a>b;
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==x) x=i;
	int lie=x/n+(x%n==0?0:1);
	x-=(lie-1)*n;
	int hang=(lie%2==0?n-x+1:x);
	cout<<lie<<" "<<hang;

	return 0;
}

