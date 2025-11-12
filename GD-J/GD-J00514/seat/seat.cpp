#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100][100]={},number[200]={},num[200]={},nn=0,kk;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			nn++;
			cin>>num[nn];	
		}
	}
	kk=num[1];
	sort(num+1,num+1+nn);
	for(int i=nn;i>=1;i--)number[nn-i+1]=num[i];	
	nn=0;
	for(int i=1;i<=m;i++){ 
		if(i%2==1){
			for(int j=1;j<=n;j++) {
				nn++;
				a[j][i]=number[nn];
				//cout<<i<<" "<<j<<endl;
			}
				
		}
		else{
			for(int j=n;j>=1;j--){
				nn++;
				a[j][i]=number[nn];
					
			}
				
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<a[i][j]<<" ";
			//cout<<j<<i<<" ";
			if(a[i][j]==kk){
				cout<<j<<" "<<i;
				break;
			}
		}
		//cout<<endl;
	}
 
	
	
	return 0;
}
