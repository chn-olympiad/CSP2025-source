#include <bits/stdc++.h>
using namespace std;
int m,n,l,c,r,q;
int a[120],a1[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int mn=m*n;
	for(int i=1;i<=mn;i++){
		cin>>a[i];
	}
	int an=a[1];
	for(int i=1;i<=mn;i++){
		for(int j=i+1;j<=mn-1;j++){
			if(a[i]<a[j]){
				q=0;
				a[j]=q;
				a[j]=a[i];
				a[i]=q;
			}
		}
	}
	for(int i=1;i<=mn;i++){
		if(an==a[i]){
			l=i;
			break;
		}
	}
	//||()
	int o=l;
	if(o%n==0){
		c=(o/n);
	}else{
		c=(o/n)+1;
	}
	if((l%n==0)){
		r=(l%n)+1;
	}else{
		r=(l%n);
	}
	if(l%n==0&&(l/n)%2==1) r+=n-1;
//	if((l-1)%n==0&&((l-1)/n)%2==1) r+=n-1;
	int y=c;
	if(c%2==0){
		r=m-r+1;
		cout<<y<<" "<<r;
	}else{
		
		cout<<y<<" "<<r;
	}
	


	return 0;
}
