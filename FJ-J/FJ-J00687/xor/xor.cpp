#include<bits/stdc++.h>
using namespace std;
int n,k;
int b[10010],v1=0,v0=0,sum=0,aa[10010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1){
			v1++;
		}else{
			v0++;
		}
	}
	int num=1,a=0;
	if(v1==n){
		for(int i=1;i<=n-1;i++){
			sum+=i;
		}
		if(k==0){
			cout<<sum;
		}else{
			cout<<0;
		}
	}else{
		for(int i=1;i<=n;i++){
			sum+=i;
		}
		if(k==1){
			cout<<v1;
		}else{
			cout<<(sum-v1);
		}
	}
	return 0;
}
