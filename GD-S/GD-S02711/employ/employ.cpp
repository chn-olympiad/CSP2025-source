#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510;
ll n,m,a[N],cnt;
string s;
bool b=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=0;i<s.size();i++) if(s[i]=='0') b=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0) cnt++;
	}
	if(b){
		cout<<cnt;
		return 0;
	}
	return 0;
}
