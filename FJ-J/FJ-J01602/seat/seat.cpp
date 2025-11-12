#include<bits/stdc++.h>
using namespace std;
int lg,n,m,x,y,rgr,r,gr[105];
int find(int g) {
	for (int i=1;i<=n*m;i++) {
		if(gr[i]==g) return i;
	}
}
int mod(int a, int b) {
	if(a%b==0) return b;
	return a%b;
}
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	gr[1]=r;
	for (int i=2;i<=n*m;i++) {
		cin>>gr[i];
	}
	sort(gr+1,gr+n*m+1,cmp);
	rgr=find(r);
	x=ceil((rgr*1.0)/n);
	if(x%2==0) y=n-mod(rgr,n)+1;
	else y=mod(rgr,n);
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
