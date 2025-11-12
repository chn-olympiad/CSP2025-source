#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a1=0,b1=0;
	int n,m,da=1;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(a[i]!=i){
			a1=1;
		}
		if(a[i]!=n*m-i+1){
			b1=1;
		}
		if(a[i]>a[1]){
			da+=1;
		}
	}
	if(a1==0){
		if(m%2==0){
			cout<<m<<' '<<1;
		}else{
			cout<<m<<' '<<n;
		}
		
	}else if(b1==0){
		cout<<1<<' '<<1;
	}else{
		int lie=(da-1)/n+1;
		int hang;
		if(lie%2==1){
			hang=da-(lie-1)*n;
		}else{
			hang=n-(da-(lie-1)*n)+1;
		}
		
		cout<<lie<<' '<<hang;
	}
	return 0;
} 