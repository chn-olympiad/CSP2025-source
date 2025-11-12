#include <bits/stdc++.h>
using namespace std;
long long n,m,a[110],c,r,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
			s=a[1];
	}
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			if((n*m-i+1)%n==0&&((n*m-i+1)/n)%2==0){
				c=(n*m-i+1)/n;
				r=1;		
			} 
			if((n*m-i+1)%n==0&&((n*m-i+1)/n)%2!=0){
				c=(n*m-i+1)/n;
				r=n;			
			}
			if((n*m-i+1)%n!=0){
				c=(n*m-i+1)/n+1;
				if(c%2==1){
				r=(n*m-i+1)-(c-1)*n;	
			}
			if(c%2==0&&(n*m-i+1)%2==1){
				r=n*c-(n*m-i+1)+1;
			}
			if(c%2==0&&(n*m-i+1)%2==0){
				r=n-((n*m-i+1)-n*(c-1))+1;
			}
			}
				cout<<c<<" "<<r;
		}
		
	}
	}
