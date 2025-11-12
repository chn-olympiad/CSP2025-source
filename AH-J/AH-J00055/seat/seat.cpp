#include<bits/stdc++.h>
using namespace std;
int n,m,a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	int c,r;
	sort(a+1,a+n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			c=i/n+1;
			if(i%n==0){
				c=c+1;
			}
			r=i%n;
			if(r==0){
				if((i/n)%2==0){
					r=1;
				}else{
					r=n;
				}
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
