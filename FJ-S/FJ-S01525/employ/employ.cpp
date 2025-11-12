#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],sum,sum1;
long long ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])sum1++;
	}
	for(int i=0;i<n;i++)
		if(s[i]=='1')
			sum++;
	if(sum<m||sum1<m)
		ans=0;
	else if(sum==n){
		ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%998244353;
		}
	else ans=n*m;
	cout<<ans;
	return 0;
}
