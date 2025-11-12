#include<bits/stdc++.h>
using namespace std;
int a[110],b[20][20],c[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	int k=1;
	int max=-1;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>max){
				max=a[j];
			}
		}
		c[i]=max;
		
		for(int j=1;j<=n*m;j++){
			if(a[j]==max) a[j]=-1;
		}
		
		max=-1;
	}
	 k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=c[k];
				k++;
				if(b[j][i]==s){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=c[k];
				k++;
				if(b[j][i]==s){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
		
	return 0;
}


