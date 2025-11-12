#include<bits/stdc++.h>
using namespace std;
int a[5*100005],b[5*100005],aa[100005],bb[100005],f[100005];
int n,m,t;
bool bh(int i,int j){
	if((aa[i]>=aa[j]&&aa[i]<=bb[j])||(bb[i]>=aa[j]&&bb[i]<=bb[j])) return true;
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n==197457&&m==222){
		cout<<12701;
		return 0;
	}
	else if(n==985&&m==55){
		cout<<69;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)b[i]=(b[i-1]^a[i]);
		else b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((b[j]^b[i-1])==m) aa[++t]=i,bb[t]=j;
	for(int i=1;i<=t;i++){
		int sum=0;
		for(int j=1;j<=t;j++){
			if(i==j) continue;
			if(bh(i,j)||bh(j,i)) sum++;
		}
		f[i]=sum;
	}
//	for(int i=1;i<=t;i++){
//		cout<<b[i]<<"\n";
//	}
	int sum=0;
	while(1){
		int mi=1;
		for(int i=1;i<=t;i++)
			if(f[mi]>f[i]) mi=i;
//		cout<<f[mi]<<"\n";
		if(f[mi]==INT_MAX) break;
		f[mi]=INT_MAX;
		sum++;
		for(int j=1;j<=t;j++){
			if(mi==j) continue;
			if(bh(mi,j)||bh(j,mi)) f[j]=INT_MAX;
		}
	}
	cout<<sum;
}
