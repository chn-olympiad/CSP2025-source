#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010101],k,kk,l,r,x;
int cmp(int x,int y){ return x>y; }
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	kk=n*m;
	for(int i=1;i<=kk;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}
	sort(a+1,a+kk+1,cmp);
	for(int i=1;i<=kk;i++){
		if(a[i]==k){
			x=i;
			break;
		}
	}
	l=((x-1)/n)+1;
	if(((x-1)/n)%2==0) r=((x-1)%n)+1;
	else r=n-((x-1)%n);
	cout<<l<<' '<<r;
	return 0;
}
