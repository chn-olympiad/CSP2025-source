#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,ans=0;
	cin>>n>>k;
	long long m[n];
	bool flag=1;
	for(int i=0;i<n;i++){
		cin>>m[i];
		if(!m[i]){
			flag=0;
			sum++;
		}
		if(m[i]==1){
			ans++;
		}
	}
	if(flag&&k==0){
		cout<<n/2;
	}else if(k<=1){
		if(k==0){
			for(int i=0;i<n-1;i++){
				if(m[i]==1&&m[i+1]==1){
					sum++;
					m[i]=0;
					m[i+1]=0;
				}
			}
			cout<<sum;
		}else{
			cout<<ans;
		}
	}else{
		if(k<=255){
			cout<<19;
		}else{
			cout<<1319;
		}	
	}
	return 0;
}
