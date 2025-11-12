#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int mod=998244353;
int n,m;
string a;
int ans;
int p[N];
int jc[N];
void init(){
	jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	a=' '+a;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(n!=m){
		cout<<0;
		return 0;
	}
	init();
	sort(p+1,p+n+1);
	int give=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='0'||p[i]==0){
			cout<<0;
			return 0;
		}
	}
	cout<<jc[n];
} 
