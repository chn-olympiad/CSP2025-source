#include<bits/stdc++.h>
using namespace std;
/*
struct nn{
	
}; */
int qqt(int a,int b){
	return a>b;
}
int a[1008],n,m,q,s,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>q;
	for(int i=1;i<n*m;i++)cin>>a[i];
	a[n*m]=q;
	sort(a+1,a+n*m+1,qqt);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			s=i;
			break;
		}
	}
	h=(s-1)/(n);
	l=s-h*n;
	if(l)h++;
	if(h%2==0)l=n-l+1;
	cout<<h<<" "<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 