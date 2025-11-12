#include <bits/stdc++.h>
using namespace std;
int n,m,a[125],xxs;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xxs=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]>a[j]){
				int p=a[j];
				a[j]=a[i];
				a[i]=p;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==xxs){
			xxs=i;
			break;
		}
	}
	int h=1,l=1;
	while(xxs){
		if(xxs-n>0){
			xxs-=n;
			l++;
		}else{
			break;
		}
	}
	while(xxs){
		if(l%2==1){
			h=xxs;
			break;
		}else{
			h=n-xxs+1;
			break;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
