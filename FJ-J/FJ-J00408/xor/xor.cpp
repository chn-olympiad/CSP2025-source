#include<bits/stdc++.h>
using namespace std;
int n,k;
int pd(int x){
	int y=0;
	while(x!=0){
		x=x<<1;
		y++;
	}
	return y;
}
long long xor_(int x,int y){
	int sum=pd(max(x,y))+1;
	bool a[sum]={},b[sum]={};
	int i=0;
	while(x!=0){
		i++;
		a[i]=x%2;
		x/=2;
	}
	i=0;
	while(y!=0){
		i++;
		b[i]=y%2;
		y/=2;
	}
	bool c[sum]={};
	for(int i=1;i<sum;i++){
		if((a[i]==0&&b[i]==1)||(a[i]==1&&b[i]==0)){
			c[i]=1;
		}else{
			c[i]=0;
		}
	}
	long long ans=0;
	for(int i=1;i<sum;i++){
		ans+=c[i]*(pow(2,i));
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i+1;j++){
			long long cnt=0;
			for(int k=j;k<=j+i-1;k++){
				cnt=xor_(cnt,a[k]);
			}
			cout<<i<<" "<<j<<" "<<cnt<<"\n";
			if(cnt==k){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
