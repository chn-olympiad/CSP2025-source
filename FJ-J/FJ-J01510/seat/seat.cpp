#include<bits/stdc++.h>
using namespace std;
int n,m,top;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	top=a[1];
	sort(a+1,a+1+n*m);
	int p=1,r,c;
	for(int i=n*m;i>=1;i--){
		if(a[i]==top){
			if(p%n==0) c=p/n;
            else c=p/n+1;
			if(c%2!=0){
				if(p%n==0) r=n;
				else r=p%n;
			} 
			else{
				if(p%n==0) r=1;
				else r=n+1-p%n;
			}
			cout<<c<<' '<<r;
			return 0;
		}
		p++;
	}
} 
