#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],sum,ans=1,cnt=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) sum++;
	}
	for(int i=1;i<=sum;i++) ans*=i;
	for(int i=1;i<=n-sum;i++) cnt*=i;
	cout<<ans*cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
