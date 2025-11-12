#include <bits/stdc++.h>
using namespace std;
int m,n,a,b[105],c[105],f,e,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	a=b[1];
	sort(b+1,b+1+m*n);
	for(int i=1;i<=n*m;i++){
		c[i]=b[m*n+1-i];
		if(c[i]==a)f=i;
	}
	if(f<=n)cout<<1<<" "<<f;
	else{
		int x=(f/n)+1;
		if(x%2==1){
			r=f%n;
		}else{
			r=n+1-(f%n);
		}
		cout<<x<<" "<<r;
	}

	return 0;
} 
