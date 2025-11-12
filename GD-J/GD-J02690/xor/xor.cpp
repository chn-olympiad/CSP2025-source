#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[25],b[25],ansa[25],x[500005];
int anum,bnum;
bool testa=true,testb=true;
int xr(int x,int y){
	int strx=0,stry=0;
	while(x!=0){
		int mod=x%2;
		strx++;
		a[strx]=mod;
		x/=2;
	}
	while(y!=0){
		int mod=y%2;
		stry++;
		b[stry]=mod;
		y/=2;
	}
	int nx=0,ny=0;
	for(int i=strx;i>=1;i--){
		nx*=10;
		nx+=a[i];
	}
	for(int i=stry;i>=1;i--){
		ny*=10;
		ny+=b[i];
	}
	int ans=0;
	for(int i=max(strx,stry);i>=1;i--){
		ans*=10;
		if(a[i]!=b[i]){
			ansa[i]=1;
			ans++;
		}
	}
	int ret=0;
	for(int i=max(strx,stry);i>=1;i--){
		ret=ret+ansa[i]*pow(2,i-1);
	}
	return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			testa=false;
		}
		if(a[i]>1){
			testb=false;
		}
		if(a[i]==1){
			anum++;
		}else if(a[i]==0){
			bnum++;
		}
	}
	if(testa==true){
		cout<<n;
		return 0;
	}else if(testb==true){
		if(k==0){
			cout<<bnum;
		}else{
			cout<<anum;
		}
		return 0;
	}
	return 0;
}











