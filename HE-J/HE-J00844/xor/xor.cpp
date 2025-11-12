#include<bits/stdc++.h>
using namespace std;
int n,k,b[100005],a[100005]={0},c[100005],m=0;
bool y[100005];
int f(int x){
	int j=0;
	for(int i=b[x];i>0;i=int(i/2.0),j++){
		a[j]+=i%2;
		if(a[j]==2){
			a[j]=0;
		}
	}
	return j;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=k,j=0;i>0;i=int(i/2.0),j++){
		c[j]=i%2;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j+i<=n;j++){
			if(b[j]==0&&k!=0){
				continue;
			}
			bool sum=0;
			for(int l=j;l<=j+i;l++){
				if(y[l]==1){
					sum=1;
					break;
				}
			}
			if(sum==1){
				continue;
			}
			int z=0;
			for(int l=j;l<=j+i;l++){
				z=max(z,f(l));
			}
			bool s=1;
			for(int l=0;l<=z;l++){
				if(a[l]!=c[l]){
					s=0;
				}
				a[l]=0;
			}
			if(s==1){
				for(int ii=j;ii<=j+i;ii++){
					y[ii]=1;
				}
				m++;
			}
		}
	}
	cout<<m;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
