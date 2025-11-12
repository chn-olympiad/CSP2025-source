#include<bits/stdc++.h>
using namespace std;
int n,zg,sum,tap;
int a[100005],b[100005];
int func(int x,int y){
  int sum=0,js=1;
	int x1[100]={0},x2[100]={0};
	int k=0;
	while(x!=0){
		if(x%2==1) x1[++k]++;
		else x1[++k]=0;
		x/=2;
	}
	int k1=k;k=0;
	while(y!=0){
		if(y%2==1) x2[++k]++;
		else x2[++k]=0;
		y/=2;
	}
	k=max(k1,k);
	for(int i=k;i>=1;i--){
		if(x1[i]!=x2[i]) x1[i]=1;
		else x1[i]=0;
	}
	for(int i=1;i<=k;i++){
		if(x1[i]==1){
			sum+=js;
		}
		js*=2;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>zg;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==zg){
			sum++;
			b[i]=1;
			}
	}
	int s=1;
	for(int i=1;i<=n;i++){
		if(b[i]==1&&i==1){
			 continue;
			 }
		else if(b[i]==1&&i!=1){
			
			for(int j=s;j<=i-1;j++){
				int sum1=a[j];
				for(int z=j+1;z<=i-1;z++){
					sum1=func(sum1,a[z]);
					if(sum1==zg){
						 tap=1;
						 
					}
				}
				if(tap){
					tap=0;
					 sum++;
					 break;
				 }
			}
			 continue;
			 int s=i+1;
		 }
		 else if(i==n&&b[i]==0){
			 for(int j=s;j<=i-1;j++){
				int sum1=a[j];
				for(int z=j+1;z<=i-1;z++){
					sum1=func(sum1,a[z]);
					if(sum1==zg){
						 tap=1;
					}
				}
				if(tap){
					tap=0;
					 sum++;
					 break;
				 }
		 }
	}
}
			cout<<sum;
}
