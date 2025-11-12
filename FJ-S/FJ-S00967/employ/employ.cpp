#include<bits/stdc++.h>
using namespace std;
int c[505],a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxn=max(maxn,c[i]);
	}
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	if(m==1){
		int f=0x3f3f3f;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				f=i;
				break;
			}
		}
		if(maxn>=f){
			ans++;
			
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			//	cout<<ans<<" ";
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
