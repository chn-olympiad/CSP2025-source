#include<bits/stdc++.h>
using namespace std;

const long long N=1e3+10,mod=998244353;
long long n,m,ans=0,t=0,st=1;
int c[N];
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" "<<ans<<endl; 
		if(c[i]<=ans){
			ans++;
			continue;
		}
		t++;
	}
	cout<<ans<<" "<<t<<endl;
	for(int i=1;i<=t;i++){
		st=(st*i)%mod;
	}
	cout<<st;
	return 0;
}
