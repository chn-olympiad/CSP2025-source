#include<bits/stdc++.h> 
using namespace std;
int n,m,b[1009],a,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	a=b[0];
	for(int i=n*m-2;i>0;i--){
		for(int j=i;j>0;j--){
			if(b[i]>b[i-1]){
				swap(b[i],b[i-1]);
			}
		}
	}
	int i=1;
	while(1){
		if(a<=b[i]){
			i++;
		}else{
			break;
		}
	}
	for(int j=1;j<=m;j++){
		if(i>n){
			i-=n;
		}else if(i==n){
			if(m%2==0){
				cout<<j<<" "<<1;
				break;
			}else{
				cout<<j<<" "<<n;
				break;
			}
		}else{
			if(m%2==0){
				cout<<j<<" "<<n-i+1;
				break;
			}else{
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	
}