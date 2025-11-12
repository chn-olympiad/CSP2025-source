#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],a1,c=1,r=1,cs=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a,a+(n*m+1));
	for(int i=n*m;i>=1;i--){
		if(a1==a[i]){
			if(cs%n!=0 && cs<=n){
				r=cs%n;
				cout<<c<<' '<<r;
				return 0;
			}else{
				if(cs%n!=0){
					c++;
					if(c%2==0){
						if(cs%n!=1){
							r=cs%n;
						}else{
							r=n-cs%n+1;
						}
					cout<<c<<' '<<r;
					return 0;
					}
				}else{
					c=cs/n;
					if(c%2==0){
						r=1;
					}
					if(c%2==1){
						r=n;
					}
					cout<<c<<' '<<r;
					return 0;
				}
			}
		}
		cs++;
	}
	return 0;
}
