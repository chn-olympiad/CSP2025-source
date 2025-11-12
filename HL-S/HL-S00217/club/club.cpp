#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;	
	int a[10001][3];
	int b[10001][3];
	for(int i=0;i<n;i++){
		int people=0;
		cin>>people;
		for(int k=0;k<people;k++){
			for(int j=0;j<3;j++){
				cin>>a[k][j];
				b[k][j]=a[k][j];
			}
		}
		
		for(int k=0;k<people;k++){
			for(int j=0;j<2;j++){
				for(int l=0;l<2-j;l++){
					if(b[k][l]<b[k][l+1]){
						swap(b[k][l],b[k][l+1]);
					}
				}
			}
		}
		int m[10001];
		for(int k=0;k<people;k++){
			m[k]=b[k][1]-b[k][0];
		}
		
		int k0=0,k1=0,k2=0;
		int x0[10001];
		int x1[10001];
		int x2[10001];
		int sum=0;
		int x0t=0,x1t=0,x2t=0;
		
		for(int k=0;k<people;k++){
			if(a[k][0]>a[k][1]&&a[k][0]>a[k][2]){
				sum=sum+a[k][0];
				k0++;
				x0[x0t]=m[k];
				x0t++;
			}
			if(a[k][1]>a[k][0]&&a[k][1]>a[k][2]){
				sum=sum+a[k][1];
				k1++;
				x1[x1t]=m[k];
				x1t++;
			}
			if(a[k][2]>a[k][1]&&a[k][2]>a[k][0]){
				sum=sum+a[k][2];
				k2++;
				x2[x2t]=m[k];
				x2t++;
			}
			
			if(a[k][0]==a[k][1]&&a[k][0]>a[k][2]){
				sum=sum+a[k][0];
				k0++;
				x0[x0t]=0;
				x0t++;
			}
			if(a[k][1]>a[k][0]&&a[k][1]==a[k][2]){
				sum=sum+a[k][1];
				k1++;
				x1[x1t]=0;
				x1t++;
			}
			if(a[k][2]>a[k][1]&&a[k][2]==a[k][0]){
				sum=sum+a[k][2];
				k2++;
				x2[x2t]=0;
				x2t++;
			}
			if(a[k][2]==a[k][1]&&a[k][2]==a[k][0]){
				sum=sum+a[k][2];
				k2++;
				x2[x2t]=0;
				x2t++;
			}
			
			
		}
		
		
		for(int k=0;k<k0-1;k++){
			for(int j=0;j<k-k0-1;j++){
				if(x0[j]<x0[j+1]){
					swap(x0[j],x0[j+1]);
				}
			}
		}
		
		for(int k=0;k<k1-1;k++){
			for(int j=0;j<k-k1-1;j++){
				if(x1[j]<x1[j+1]){
					swap(x1[j],x1[j+1]);
				}
			}
		}
		
		for(int k=0;k<k2-1;k++){
			for(int j=0;j<k-k2-1;j++){
				if(x2[j]<x2[j+1]){
					swap(x2[j],x2[j+1]);
				}
			}
		}
		
		int people1;
		if(people%2==0){
			people1=people/2;
		}
		else{
			people1=people/2;
		}
		
		
		
		if(k0>people/2){
			for(int k=0;k<k0-people1;k++){
				sum=sum+x0[k];
			}
		}
		
		else if(k1>people/2){
			for(int k=0;k<k1-people1;k++){
				sum=sum+x1[k];
			}
		}
		
		else if(k2>people/2){
			for(int k=0;k<k2-people1;k++){
				sum=sum+x2[k];
			}
		}
		cout<<sum<<endl;
		
	}
	return 0;
} 
