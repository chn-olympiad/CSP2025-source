#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]==0)cnt++;}
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum=sum*i%998244353;
	}
	if(n-cnt<m) cout<<sum-cnt;
	else cout<<sum;
	return 0;
}
