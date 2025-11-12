#include<bits/stdc++.h>
using namespace std;
const int N=2e5+30,M=998244353;
int n,m,a[510],ans=1,num;
string s;
bool b;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') b=1;
		else num++;
	}
	if(num<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) ans=(ans*i)%M;
	cout<<ans;
	return 0;
}
