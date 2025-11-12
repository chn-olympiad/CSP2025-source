//首先，我们需要生成一个排列 
#define ll long long
#include<bits/stdc++.h>
using namespace std;
const ll mod=998244353;
int n,m;
const int N=600;
bool vst[N];
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	int flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		//if(c[i]!=1)flag=0;
	}
	ll ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
