#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,c,r;
	cin>>n>>m;
	int a[111105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int p;
			if(i%n==0){
				p=i/n;
			}else{
				p=i/n+1;
			}
			if(p%2==0){
				c=p;
				r=n-(i%n)+1;
			}else if(p%2!=0){
				c=p;
				if(i%n==0){
					r=n;
				}else{
					r=i%n;
				}
			}
			cout<<c<<' '<<r<<'\n';
			return 0;
		}
	}
	return 0;
}
