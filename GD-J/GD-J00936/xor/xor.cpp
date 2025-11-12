#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s;
	cin>>n>>k;
	int a[n+1],b[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]^a[i-1];
	}
	int m=0;
	int l=n-1;
	while((a[l]^a[n])!=k){
		l--;
	}
	for(int i=n;i>=l;i--){
		s=0;
		for(int j=i;j>0;j--){
			while(a[j-1]^a[i]!=k)j--;
			s++;
		}
		m=max(m,s);
	}
	cout<<m;
}
