#include<bits/stdc++.h>
using namespace std;
long long u[1000];
long long v[1000];
long long w[1000];
long long c[10000]={};
long long b[10000][10000]={};
int t[10000]={};
int f[10000]={};
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	int min2=100000,min1=100000,min=100000,j1;
	cin>>n>>m>>k;
	int u1[10000]={};
	int v1[10000]={};
	int sum=0;
	for(int o=1;o<=m;o++){
		cin>>u[o]>>v[o]>>w[o];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int z=1;z<=n;z++){
			cin>>b[j][z];
		}
	}	
	for(int i=1;i<=m;i++){
		for(int o=1;o<=m;o++){
			if(w[o]<min){
				min=w[o];
				u1[i]=u[o];
				v1[i]=v[o];
			}
		}
	}
	sum+=min;
	for(int i=1;i<=m;i++){
		for(int o=1;o<=m;o++){
			if(w[o]<min1&&w[o]!=min){
				min1=w[o];
				u1[i]=u[o];
				v1[i]=v[o];
			}	
		}
	}
	sum+=min1;
	for(int h=1;h<=n;h++){
		for(int i;i<=m;i++){
			if(u1[i]==h||v1[i]==h){
				t[i]=h;
			}else{
				f[i]=h;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int o=1;o<=m;o++){
			for(int j=1;j<=k;j++){
				for(int z=1;z<=n;z++){
					if(c[j]<=min2){
						min2=c[j];
						j1=j;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			for(int z=1;z<=n;z++){
				for(int h=1;h<=n;h++){
					if(u1[i]==h||v1[i]==h){
						t[i]=h;
					}else {
						f[i]=h;
					}
				}
			}
		}
 	}
 	for(int i=1;i<=m;i++){
 		for(int j=1;j<=m;j++){
 			if(f[j]==t[i]){
 				f[j]=0;
			 }
		 }
	 }
 	for(int i=1;i<=m;i++){
		sum+=b[j1][f[i]];
 	}
	sum+=min2;
	cout<<sum+1; 
return 0;
}
