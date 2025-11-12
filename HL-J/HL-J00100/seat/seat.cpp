#include <bits/stdc++.h>
using namespace std;
int a[110],m,n;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int fin=a[1],len=n*m,r=1;
	for(int i=2;i<=len;i++){
		if(a[i]>fin) r++;
		
	}
	int c=r/n,l=r%n;
	if(l==0){
		if(c%2==1) cout<<c<<' '<<n;
		else cout<<c<<' '<<0; 
	}else{
		c+=1;
		if(c%2==0) cout<<c<<' '<<n+1-l;
		else cout<<c<<' '<<l;
	}
	return 0;
}