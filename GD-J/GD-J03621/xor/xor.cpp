#include<bits/stdc++.h>
using namespace std;
long long n,i,k,a[10001],ans,j,l,x[10001],y[10001],ly,m,z,v[10001],as[10001],c=1,xx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){
		ans=0;
		for(j=i+1;j<=n;j++){
			for(l=i;l<=j;l++){
				ans^=a[l];
				if(ans==k) x[++m]=i,y[++m]=j;
			}
		}
	}
	while(z<m){
		ly=0;
		for(i=1;i<=m;i++){
			if(x[i]>ly&&v[i]==0){
				ly=y[i];
				as[c]++;
				v[i]=1;
				z++;
			}
		}
		c++;
	}
	for(i=1;i<=c;i++){
		xx=max(xx,as[i]);
	}
	cout<<xx;
	return 0;
}
