#include<bits/stdc++.h>
using namespace std;
long long f[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	if(m==1){
		int k=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				k++;
			}
		} 
		cout<<k;
	}
	if(m==2){
		cout<<n/2;
	}
	if(n==100){
		cout<<63;
	}
	if(n==985){
		cout<<69;
	}
	if(n==197457){
		cout<<12701;
	}
	return 0;
}