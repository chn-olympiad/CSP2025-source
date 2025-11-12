#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int w[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=1;
	
	for(int i=1;i<=n*m;i++){
		cin>>w[i];
	}
	int t=w[1];
	sort(w+1,w+n*m+1,greater<int>());	
	int k=0;
	for(int j=1;j<=m;j++){
		if(flag==1){
			for(int i=1;i<=n;i++){	
				k++;
				a[i][j]=w[k];
				if(k%n==0){
					flag=0;
				}
				
			}
		}
		else{
			for(int i=n;i>=1;i--){	
				k++;
				a[i][j]=w[k];
				if(k%n==0){
					flag=1;
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==t){
				cout<<j<<" "<<i;
				return 0;
			}
			
		}
		cout<<endl;
	}
return 0;
}
