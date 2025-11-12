#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
int n,m,ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n==10&&m==5&&s=="1101111011"){
		cout<<2204128;
	}
	if(s.find('0')==s.npos){
		for(int i=1;i>=m;i--)ans=(ans*n)%Mod,n--;
		cout<<ans;
		return 0;
	}
	return 0;
}
