#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std; 
int n,m,a[105],r,r1,h,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r1=i;
		}
	}
	l=ceil(r1*1.0/n);
	h=r1%n;
	if(l%2==0)h=(h+1)%n;
	if(h==0)h=n;
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}