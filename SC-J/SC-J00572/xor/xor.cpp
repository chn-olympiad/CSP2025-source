#include<bits/stdc++.h>
using namespace std;
const long long N=1e5*5+3;
long long a[N];
int have=1,ans=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) have+=1;
		else{
			ans=max(ans,have);
			have=0; 
		} 
	}
	ans=max(ans,have);
	if(k==0){
		cout<<ans;
	}
	return 0;
} 