#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int sum=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)sum--;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1')cnt++;
	}
	if(sum<m||cnt<m){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	return 0;
}
