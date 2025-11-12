#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long s=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]>a[j]){
				long long c=a[i];
				a[i]=a[j];
				a[j]=c;
			
			}
		}
	}
	long long x=0;
	for(int i=1;i<=n*m;i++){
		x++;
		if(a[i]==s){
			i=n*m+1;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(x<=n){
			cout<<"1"<<" "<<x<<" "; 
			return 0;
		}
		for(int j=2;j<=m;j++){
			if(x<=n*j){
				int s=(j-1)*n;
				if(j%2==0){
					cout<<j<<" "<<n-x+s+1;
				}else{
					cout<<j<<" "<<x%n;
				}
				return 0;
			}
		}
		//cout<<a[i]<<" ";
	}
	return 0;
} 