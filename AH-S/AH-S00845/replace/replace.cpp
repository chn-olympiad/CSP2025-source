#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+25,M=2e6+25,p1=1e9+7,p2=1e9+9;
ll n,po[4][N],inv[4][N];
string s[4][N],t[4];
bool b[N];
void solve1(){
	cin>>t[1]>>t[2];
	if(t[1].size()!=t[2].size()){cout<<"0\n";return;}
	ll i,cnt=0;
	for(i=1;i<=n;i++){
		ll siz=s[1][i].size();
		for(ll j=0;j+siz-1<t[1].size();j++){
			for(ll k=0;k<t[1].size();k++)
				if(t[1][k]!=t[2][k])b[k]=1;
				else b[k]=0;
			ll k;bool flag=1;
			for(k=j;k<=j+siz-1;k++)
				if(t[1][k]!=s[1][i][k-j]||t[2][k]!=s[2][i][k-j]){
					flag=0;
					break;
				}else b[k]=0;
			if(!flag)continue;
			for(k=0;k<t[1].size();k++)
				if(b[k]){flag=0;break;}
			if(flag)cnt++;//cout<<i<<' '<<j<<'\n';
		}
	}
	cout<<cnt<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++)cin>>s[1][i]>>s[2][i];
	while(q--)solve1();
	return 0;
}
