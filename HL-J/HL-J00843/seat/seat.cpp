#include<bits/stdc++.h> 
using namespace std;
int a[101]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l;
	cin>>n>>m;

	for(int i=1;i<=n*m;i++){		
			cin>>a[i];
			if(i==1) l=a[i];	
	}
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=i;j++){
				if(a[j]<a[j+1]){
					swap(a[j],a[j+1]);
				}
		}
	}
		for(int i=1;i<n*m;i++){
		if(a[i]==l){
			if(i%m==0){
				cout<<i/m<<" "<<m;
			}
			else{
				cout<<i/m+1<<" "<<i%m;
			}
		}
	}
	return 0;
}
