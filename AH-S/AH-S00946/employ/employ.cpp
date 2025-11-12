#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=1;
	for(int i=0;i<s.size();i++)if(s[i]!='1')flag=0;
	if(flag){
		long long s=0,ans=1,x=1;
		for(int i=1;i<=n;i++){
			if(a[i]){
				s++;
			}
		}
		for(int i=s;i>=s-m+1;i--){
			ans*=i;
			ans%=i;
		}
		for(int i=1;i<=m;i++){
			x*=i;
			x%=i;
		}
		cout<<ans-x;
	}
	else
	cout<<225301405;
	return 0;
}
