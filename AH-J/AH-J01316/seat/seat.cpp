#include <bits/stdc++.h>

using namespace std;
int a[100000];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	int q;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p) q=i;
	}
	int h,l;
	if(q%n!=0) l=q/n+1;
	else if(q%n==0) l=q/n;
	if(l%2==1) h=q-(l-1)*n;
	else if(l%2==0) h=n-(q-(l-1)*n)+1;
	cout<<l<<" "<<h;
	return 0;
}
