#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],b[500001],c[500001],sum=0;
bool dfs(int x,int y){
	for(int i=x;i<=y;i++){
		if(c[i]==1) return false;
	}
	return true;
}
void dfs1(int x,int y){
	for(int i=x;i<=y;i++){
		c[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){		
		cin >> a[i];
		b[i]=(a[i]^b[i-1]);
		if(a[i]==k){
			sum++;
			c[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((b[i-1]^b[j])==k && dfs(i,j)==true){
				sum++;
				dfs1(i,j);
			}
		}
	}
	cout << sum;
	return 0;
}

