#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
long long x(long long a1,long long b1){
	cout<<3;
	int a2[500010]={};
	int b2[500010]={};
	int x[500010]={};
	int i=1;
	while(a1){
		a2[i]=a1%2;
		a1/=2;
		i++;
	}
	int j=1;
	while(b1){
		b2[j]=b1%2;
		b1/=2;
		j++;
	}
	for(int k=1;k<=max(i,j);k++){
		if(a2[k]==b2[k]){
			x[k]=0;
		}else{
			x[k]=1;
		}
	}
	long long ans=0;
	int k=0;
	for(int u=max(i,j);u>=1;++u){
		ans+=x[u]*pow(2,k);
		k++;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ans=0;
	cout<<x(1,2);
	for(int i=1;i<=n;++i){
		cout<<b[i]<<' ';
	}
	return 0;
}
