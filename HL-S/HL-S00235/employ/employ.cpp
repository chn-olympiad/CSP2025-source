#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[800];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0){
			cnt++;
		}
	}
	long long ans=1;
	for(long long i=1;i<=cnt;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans<<" "<<cnt;
} 
