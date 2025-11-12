#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],n,k,x,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) x++;
		if(a[i]==0) p++;
	}
	if(x==n&&k==0){
		cout<<n/2;
		return 0;
	}
	if(p==n&&k==0){
		cout<<n;
		return 0;
	}
	if(k==1){
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i+1]==1){
			p+=1;
			i++;
		}
	}
	cout<<p;
	return 0;
} 
