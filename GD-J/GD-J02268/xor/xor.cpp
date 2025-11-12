#include<bits/stdc++.h>
using namespace std;
int n,k,maxx;
int a[5000005],A[5000005],sum,b[5000005];
int yh(int l,int r){
	int x=a[l];
	for(int i=l+1;i<=r;i++){
		x=x^a[i];
	}
	return x;
}
void biao(int l,int r){
	for(int i=l;i<=r;i++){
		b[i]++;
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(yh(i,j)==k){
				sum++;
				biao(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,b[i]);
	}
	cout<<sum-maxx+1;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	return 0;
}
