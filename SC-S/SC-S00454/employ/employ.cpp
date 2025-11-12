#include<bits/stdc++.h>
using namespace std;
int a[505];
const int ii=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k=1,l=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		k&=s[i];
		if(s[i]==1) l++;
	} 
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k){
		int ans=1,q=0;
		for(int i=n;i>1;i--){
			ans*=i;
			ans%=ii;
		}
		cout<<ans;
		return 0;
	}
	if(m==n&&k){
		cout<<1;
		return 0;
	}
	return 0;
}
