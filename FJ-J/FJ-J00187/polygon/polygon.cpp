#include<bits/stdc++.h>
using namespace std;
int l[5005],n;
long long k,p,q;
long long jc(int x,int y){
	int w=1;
	for(int i=x;i<=y;++i)
		w*=i;
	return w;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>l[i];
	sort(l+1,l+n+1);
	p=1;
	if(l[n]==1){
		for(int i=3;i<=n;++i){
			p=jc(1,i); 
			k+=jc(n-i+1,n)/p;
			k=k%998244353;
		}
		cout<<k;
	}else if(n==3){
		if(l[1]+l[2]>l[3])
			cout<<1;
		else
			cout<<0; 
	}else{
		for(int i=3;i<=n;++i){
			p=jc(1,i); 
			k+=jc(n-i+1,n)/p;
			k=k%998244353;
		}
		cout<<k;
	}
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	return 0;
} 
