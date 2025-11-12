#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
int a[510];
string s;
long long ans=1,cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			if(a[i]<=m){
				ans*=(a[i]-cnt); cnt++;
			}
			else{
				ans*=(m-cnt);
				cnt++;
			}
			ans%=mod;
		}
		if(cnt==m) break;
	}
	cout<<ans;
	return 0;
}
