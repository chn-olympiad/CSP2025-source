#include<bits/stdc++.h>
using namespace std;
long long k,a[500009],n ;
int Xor(int x,int y){
	int nx[109],ny[109],k1=1,k2=1,s=0;
	while(x){
		nx[k1]=x%2;
		k1++;
		x/=2;
	}
	while(y){
		ny[k2]=y%2;
		k2++;
		y/=2;
	}
	for(int i=1;i<=max(k1,k2)-1;i++){
		ny[i]=nx[i]+ny[i];
		if(ny[i]==2)ny[i]=0;
		if(ny[i]==1){
			int s1=1;
			for(int j=1;j<=i-1;j++){
				s1*=2;
			}
			s+=s1;
		}

	}
	return s;
}
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0,l1=0,l2=0;
	Xor(5,2);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=Xor(sum,j);
			if(sum==k){
				l1=max(l1,j-i);
			}
		}
	}
	sum=0;
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			sum=Xor(j,sum);
			if(sum==k){
				l2=max(l2,i-j);
			}
		}
	}
	cout<<max(l1,l2);
	return 0;
}
