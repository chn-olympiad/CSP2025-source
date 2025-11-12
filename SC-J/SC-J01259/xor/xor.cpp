#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k;
int x[2048576];
bool v=true,v0=true;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(v==true){
			if(x[i]==0){
				v=false;
			}
		}
		if(v0==true){
			if(x[i]>=1){
				v0=false;
			}
		}
	}
	if(k==0&&v){
		cout<<0;
	}
	if(v0){
		int c1=0,c0=0;
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				c1++;
			}else{
				c0++;
			}
		}
		cout<<min(c0,c1);
	}
	return 0;
}