#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat,in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int z=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}else{
				continue;
			}
		}
	}int te;
	for(int i=1;i<=n*m;i++){
		if(a[i]==z){
			te=i;
			break;
		}
	}
	int bc,b;
	b=te/n;bc=te%n;
	if(bc==0){
		if(b%2==0){
			cout<<b<<' '<<1;
		}else if(b%2==1){
			cout<<b<<' '<<n;
		}
	}else{
		if(b%2==0){
			cout<<b+1<<' '<<bc;
		}else if(b%2==1){
			cout<<b+1<<' '<<n-bc+1;
		}
	}
	
	return 0;
}
