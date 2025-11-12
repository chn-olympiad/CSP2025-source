#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
long long a[1005],n,k,b[1005],c[1005][1005];
int go(int x,int y,int k,int l){
	if(y<n){
		if(c[x][y]&&x<n){
			return go(x+1,y+1,k+1,y+1);
		}else{
			return go(x,y+1,k,l);
		}
	}else if(x<n){
		return go(x+1,l,k,l);
	}
	return k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		if(b[i]==k){
			c[1][i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(b[i]^b[j]==k){
				c[j+1][i]=1;
			}
		}
	}
	int sum=go(1,1,0,0);
	cout<<sum-1;
	return 0;
}