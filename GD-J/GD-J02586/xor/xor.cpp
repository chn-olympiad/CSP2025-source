#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,k,d=1,s=0,ans=0;
int a[500005];
int a1[500005];
void check(int i){
	s+=a[i];
	if(s==k){
		ans++;
	}
	for(int j=i+1;j<=n;j++){
		check(j);
		s-=a[i];
	}
}
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (i=1;i<=n;i++){
		cin>>m;
		if(m==k){
			ans++;
		}
		a[i]=m;
	}
	for(i=1;i<=n-1;i++){
		check(i); 
	}
	cout<<ans;
}
