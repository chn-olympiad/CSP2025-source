#include<bits/stdc++.h>
using namespace std;
int n,k,m,p;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			m++;
		}else if(a[i]==0){
			p++;
		}
	}
	if(m==n){
		cout<<n/2;
		return 0;
	}else if(k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i-1]==1){
			p++;
			a[i]=0;
		}
	}
	cout<<p;
	return 0;
		}
		if(k==1){
			cout<<m;
			return 0;
		}
	}
	return 0;
} 
