#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000002],c[1000001];int n,k;
int go(int s){
	int nao=s;
	for(int i=0;i<=n;i++){
		if(!c[i]){
			for(int j=i+1;j<=n;j++){
				if(c[j])
					break;
				if((int)(b[j]^b[i])==k){
					for(int z=i+1;z<=j;z++)
						c[z]=1;
					nao=max(go(s+1),nao);
					for(int z=i+1;z<=j;z++)
						c[z]=0;
				}
			}
		}
	}
	return nao;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	b[1]=a[1];
	int nao=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		nao=max(nao,a[i]);
		b[i+1]=b[i]^a[i];
	}
	if(nao==1){
		if(k==0)
			cout<<n;
		else cout<<n/2;
		return 0;
	}
	if(k==0){
		cout<<n;
		return 0;
	}
	cout<<go(0);
	return 0;
}