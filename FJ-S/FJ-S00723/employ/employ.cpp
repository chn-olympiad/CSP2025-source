#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long ans=1;
bool s[505];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string abcdefg;
	cin>>n>>m>>abcdefg;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<abcdefg.length();i++)
		if(abcdefg[i]=='1')s[i+1]=false;
		else s[i+1]=true;
	for(int i=1;i<=n;i++)
		if(!s[i]){
			cout<<0;
			return 0;
		}
	for(int i=1;i<=n;i++)
		ans*=i;
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
