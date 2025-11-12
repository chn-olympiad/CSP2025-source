#include<bits/stdc++.h>
using namespace std;

	int m,n=0,c[10][10],a[100],f,d;
	bool s(int b,int d){
		
		return b>d;
	}
	
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}

	f=a[0];
	sort(a,n*m+a,s);
	
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				
					c[i][j]=a[d];
					d++;
				
			
			}
		}else {
			for(int j=n;j>=1;j--){
			
					c[i][j]=a[d];
					d++;
				
			
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==f){
				m=i;
				n=j;
				break;
			}
		}
	}
	cout<<m<<" "<<n;
	return 0;
} 
