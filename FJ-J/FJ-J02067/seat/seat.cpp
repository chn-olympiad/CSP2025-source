#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,a[105],r,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){ 
		    int y=n*m-i+1;
			if(y%n==0){
				s=y/n;
			}else{
				s=y/n+1;
			}
			cout<<s<<" ";
			if(s%2==1){
				if(y%n==0){
					cout<<n;
				}else{
					cout<<y%n;
				}
			}else{
				if(y%n==0){
					cout<<1;
				}else{
					cout<<n-y%n+1;
				}
			}
			break;
		}
	}
	return 0;
}
