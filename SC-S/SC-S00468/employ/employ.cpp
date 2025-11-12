#include<bits/stdc++.h>
using namespace std;
const int N=510,p=998244353;
int n,m,a[N];
bool f[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') flag=false;
	}
	if(flag){
		int sum=1;
		for(int i=1;i<=n;i++) sum=sum*i%p;
		cout<<sum;
		return 0;
	}
	return 0;
}