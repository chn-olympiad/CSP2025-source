#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int c=b[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i]>b[j]){
			int t=b[i];
			b[i]=b[j];
			b[j]=t;
		}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==c){
			if(i%2==0){
				cout<<i/m+2<<" "<<1;
			}
			else if(i%2!=0){
				cout<<i/m+1<<" "<<n;
				
			}
			else{
				cout<<i/m+i%m+1<<" "<<1;
			}
		}
	}
	return 0;
}
