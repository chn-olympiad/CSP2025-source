#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[150],a1,b=1,c=1;
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a1>a[i]){
			cout<<b<<" "<<c; 
		}else{
			if(i==m){
				b++;
			}else{
				c++;
			}
		}
	}
	return 0;
}
