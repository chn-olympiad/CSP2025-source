#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=n*m,s,c,r;
	for(int i=1;i<=p;i++) cin>>a[i];
	sum=a[1];
	sort(a+1,a+1+p,cmp);
	for(int i=1;i<=p;i++){
		if(a[i]==sum){
			s=i;
			break;
		}
	}
	if(s%n!=0) c=s/n+1;
	else c=s/n;
	if(s%n==0){
		if(c%2) r=n;
		else r=1;
	}
	else{
		if(c%2) r=s%n;
		else r=n-s%n+1;	
	}
	cout<<c<<' '<<r;
	return 0;
}
