#include<bits/stdc++.h>
#define int long long int 
using namespace std;
const int N=5e3+10;
const int mo=998244353;
int n,m,c[N],ans=1,num=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n;i>=1;i--){
		ans=(ans*i)%mo;
	}
	cout<<ans%mo;
}
//Ren5Jie4Di4Ling5%
