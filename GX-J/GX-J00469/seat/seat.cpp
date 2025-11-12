#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,i;
	cin>>n>>m;
	long long t=n*m,a[t],r,z,x=1,y=1;
	for(i=0;i<t;i++) cin>>a[i];
	r=a[0];
	sort(a,a+t,cmp);
	for(i=0;i<t;i++){
		if(a[i]==r) z=i;
	}
	while(z>0){
	     if(y%2!=0){
		     if(x<n) x++;
             else y++;
	     }else{
		     if(x>1) x--;
		     else y++;
		 }
		 z--;
	}
	cout<<y<<" "<<x;
	return 0;
}
