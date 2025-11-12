#include<bits/stdc++.h>
using namespace std;
int n,m,r,b,h,l;
bool jx(int a,int b){
	if(a>b) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	int a[c+1];
	for(int i=1;i<=c;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+c+1,jx);
	for(int i=1;i<=c;i++) 
		if(a[i]==r) b=i;
	l=(b-1)/n+1;
	if(l%2!=0){
		if(b%n==0) h=n;
		else h=b%n;
	}
	else{
		if(b%n==0) h=1;
		else h=n+1-b%n;
	}
	printf("%d %d",l,h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
