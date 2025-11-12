#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
int n,m;
int a[510];
string s;
int p;
int y;
int t;
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=0;i<s.size();i++){
		p+=(s[i]=='1');
	}
	if(p==n){
		y=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				p--;
				y++;	
			}
		}
//		cout<<y<<endl;
		for(int i=1;i<=n;i++){
			if(a[i]<=y&&a[i]!=0) p--;
		}
//		cout<<p<<endl;
		ans=1;
		for(int i=2;i<=p;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}


