#include<bits/stdc++.h>
using namespace std;
int n,k,a[500004],fz[500004];
int b[44],c[44],nw[44];
int change(int m){
	int k=0;
	while(m>0){
		b[44-k]=m%2;
		m/=2;
		k++;
	}
	return k+1;
}
int chang2(int m){
	 int p=0;
	while(m>0){
		c[44-p]=m%2;
		m/=2;
		p++;
	}
	return p+1;
}
int xr(int p,int k){
	int pk=max(p,k);
	for(int i=44;i>=pk;i--){
		if(b[i]!=c[i])nw[i]=1;
		else nw[i]=0;
	}
	return pk;
}
int over(){
	for(int i=1;i<=44;i++){
		b[i]=0;
		c[i]=0;
		nw[i]=0;
	}
	return 0;
}
int change3(int pk){
	int cnt=0,k=0;
	for(int i=44;i>=pk;i--){
		cnt+=pow(2,k);
		k++;
	}
	return cnt;
}
int po(int j,int i){
	for(j;j<=i;j++){
		int k=change(fz[j]);
		int p=change(fz[j+1]);
		fz[j+1]=change3(xr(k,p));
		over();
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fz[i]=a[i];
		if(a[i]==k){
			ans=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			po(j,i);
			if(fz[i]==k)ans=max(ans,i-j+1);
		}
		
		for(int i=1;i<=n;i++){
			fz[i]=a[i];
		}
	}
	cout<<ans;
}
