#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100000][3];
bool ans[100000]={0};
bool pd(int k,int h){
	int saml=a[k][h];
	for(int i=1;i<=3;i++){
		if(saml<a[k][i]){
			return 0;
		}
	}
	return 1;
}
int qk(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
		a[i][j]=0;
		}	
	}
	
}
int qk2(int n){
	for(int i=1;i<=n;i++){
		ans[i]=0;
			
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n;
		int cnt=n/2;
		int sum=0;
		qk(n);
		for(int sk=1;sk<=n;sk++){
			for(int j=1;j<=3;j++){
				cin>>a[sk][j];
			}
		}
		
		for(int h=1;h<=3;h++){
			qk2(n);
			for(int l=1;l<=cnt;l++){
				int saml=-1;
				for(int k=1;k<=n;k++){
					if(saml<=a[k][h]&&ans[k]==0&&pd(k,h)){
						saml=a[k][h];
						ans[k]=1;
					}
				}
				if(saml!=-1){
					
					sum+=saml;
				} 	
			}
		}
		cout<<sum<<endl;		
	}

	return 0;
}
