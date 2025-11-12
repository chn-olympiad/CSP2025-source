#include<bits/stdc++.h>
using namespace std;
int t,o;
int n[6],sum[6]={0,0,0,0,0,0};
int a1[6][10005],a2[6][10005],a3[6][10005];
bool A[6]={1,1,1,1,1,1},B[6]={1,1,1,1,1,1};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a1[i][j]>>a2[i][j]>>a3[i][j];
			if(a2[i][j]!=0){
				A[i]=false;
			}else if(a3[i][j]!=0){
				B[i]=false;
				A[i]=false;
			}
		}
	}

		
	for(int i=1;i<=t;i++){
			int b1[10005],b2[10005],b3[10005];
			for(int j=1;j<=n[i];j++){
				b1[j]=j;
				b2[j]=j;
				b3[j]=j;
			}
		if(B[i]){
			for(int j=1;j<=n[i];j++){
			for(int k=j;k<=n[i];k++){
				if(a1[i][j]<a1[i][k]){
					int q;
					q=a1[i][j];
					a1[i][j]=a1[i][k];
					a1[i][k]=q;
					q=b1[j];
					b1[j]=b1[k];
					b1[k]=q;
				}
				if(a2[i][j]<a2[i][k]){
					int q;
					q=a2[i][j];
					a2[i][j]=a2[i][k];
					a2[i][k]=q;
					q=b1[j];
					b2[j]=b2[k];
					b2[k]=q;
				}
			}
		}
	}
		int b1n=n[i]/2,b2n=n[i]/2;			
		for(int j=1;j<=n[i];j++){
			if(b1n>0){
				if(b2n>0&&a1[i][j]<a2[i][b2[j]]||b2[j]>=n[i]/2){ 
			 	sum[i]+=a2[i][b2[j]];
			 	b2n--;
				cout<<b2n;
			 	b2[j]=0;
			 	continue;
			 }
				}else{
					sum[i]+=a1[i][j];
					b1n--;
				}
			
}
		for(int j=1;j<n[i];j++){
			if(b2n>0&&b2[j]!=0){
				sum[i]+=a2[i][j];
			}
		}
		 for(int j=1;j<=n[i];j++){
		 	cout<<a1[i][j]<<" ";
		 	cout<<a2[i][j]<<" ";
		 }
	}
		

	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			for(int k=j;k<=n[i];k++){
				if(a1[i][j]<a1[i][k]){
					int q;
					q=a1[i][j];
					a1[i][j]=a1[i][k];
					a1[i][k]=q;
				}
				if(a2[i][j]<a2[i][k]){
					int q;
					q=a2[i][j];
					a2[i][j]=a2[i][k];
					a2[i][k]=q;
				}
				if(a3[i][j]<a3[i][k]){
					int q;
					q=a3[i][j];
					a3[i][j]=a3[i][k];
					a3[i][k]=q;
				}
			}
		}
		if(A[i]){
			for(int j=1;j<=n[i]/2;j++){
				sum[i]+=a1[i][j];
		 }
		}
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
