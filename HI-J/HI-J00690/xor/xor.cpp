#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long n,k;
bool yh(int x,int y){
	int h=a[x]^a[x+1];
	for(int i=x+1;i<y;i++){
		h+=h^a[i+1];
	}
	if(h==k){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-2e9;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yh(i,j)==true){
				maxn=max(maxn,j-i+1);
			}
		}
	}
	if(maxn>0){
		cout<<maxn;
	}
	else{
		cout<<1;
	}
	return 0;
}
