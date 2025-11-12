#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],as;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	as=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==as){
			i=m*n-i+1;
			int l=i%n,r=i/n;
			if(l>0){
				r+=1;
			}
			if(l==0) l=n;
			if(r%2==1){
				cout<<r<<" "<<l;
				return 0;
			}else{
				cout<<r<<" "<<n-l+1;
				return 0;
			}
		}
	}
	return 0;
} 