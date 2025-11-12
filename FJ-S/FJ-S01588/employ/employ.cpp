#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=1;

long long c[100000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	string s;
	cin>>s;
	int f=0;
	for(int i=0;i<n;i++){
		if(s[i]==0) f=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]==0){
				k++;
			} 
		}
		cout<<k;
		if(k>n-m){
			cout<<0;
			return 0;
		}
		for(long long i=n-k;i>=n-k-m+1;i--){
			ans*=i;
			cout<<ans<<" ";
		}
		for(long long i=1;i<=m;i++){
			ans/=i;
			cout<<ans<<" ";
		}
		ans%=998244353;
		cout<<ans;
	}
	return 0;
}







