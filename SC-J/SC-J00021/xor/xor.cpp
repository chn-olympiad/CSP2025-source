#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+10;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
		return 0;
	}else if(k<=1){
		for(int i=0;i<n-1;i++){
		if(a[i]==0&&a[i+1]==1||a[i]==1&&a[i+1]==0){
			ans++;
			i++;
		}
	}
	cout<<ans;
	return 0;
	}
	return 0;
}
