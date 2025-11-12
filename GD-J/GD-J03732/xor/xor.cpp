#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k;
int a[N],s[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>> a[i];
		if(i==1){
			s[i]=a[i];
		}
		else{
			s[i]=s[i-1]^a[i];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(abs(s[i]-s[j])==k){
				ans=max(ans,i-j);
			}
		}
	}
	cout<<ans;
	return 0;
}
