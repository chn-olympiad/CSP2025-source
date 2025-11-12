#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int cnt=0;
int check(int zhan[],int z){
	int sum=0,maxa=0;
	for(int i=0;i<z;i++){
		sum+=zhan[i];
		maxa=max(maxa,zhan[i]);
	}
	if(sum>(2*maxa)){
//		for(int i=0;i<z;i++){cout<<zhan[i]<<' ';}
//		cout<<endl;
		return 1;
	}
	else return 0;
}

void pai(int i,int n,int zhan[],int z,int k){
	int i1=i;
	while(i<=n){
		if(z<k){
			zhan[z]=a[i];
			z++;
			i++;
		}else{
			cnt+=check(zhan,z);
			zhan[z]=0;
			z--;
		}
		if(i==n+1){
			i=i-(k-i1);
			z-=k-1;
			i1=i;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int k=3;k<=n;k++){
		for(int j=0;j<=n-k;j++){
			int z=0,zhan[5005]={0};
			zhan[z]=a[j];
			z++;
			for(int i=j+1;i<n;i++){
				pai(i,n,zhan,z,k);
			}
		}
	
	}
	
	cout<<cnt;
	return 0;
}
