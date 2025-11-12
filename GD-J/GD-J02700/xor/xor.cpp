#include<bits/stdc++.h>
using namespace std;
int num[500010];
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	num[0]=0;
	for(int i=1;i<=n;i++){
		num[i]^=num[i-1];
	}
	int sum=0,bj=1;
	bool fg=0;
	for(int i=1;i<=n;i++){
		fg=0;
		for(int j=i;j<=n;j++){
			int ans=0;
			ans=num[j]^num[i-1];
			if(ans==k){
				sum++;
				bj=j;
				fg=1;
				break;
			}
		}
		if(fg){
			i=bj+1;
		}
	}
	cout<<sum;
	return 0;
}
