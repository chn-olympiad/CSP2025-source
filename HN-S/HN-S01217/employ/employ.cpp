#include<bits/stdc++.h>
using namespace std;
#defint int long long
int a[505];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0,sum=0;
	string s;
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<s.size;i++) if(s[i]=='1') cnt++;
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(cnt==n){
		sum++;
		for(int i=1;i<=n;i++){
			sum*=i;
			sum%=i;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<sum;
	return 0;
} 
