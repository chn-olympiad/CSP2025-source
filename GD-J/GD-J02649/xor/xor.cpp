#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,p,l,maxs;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m+=a[i];
		if(a[i]==1)p++;
		else l++;
	}
	if(m==n){
		if(k==0){
			cout<<n/2;
			return 0;
		}else{
			cout<<n;
			return 0;
		}
	}
}
