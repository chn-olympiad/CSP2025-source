#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,c[510],cnt;
string s;
bool f=true;
ll fact(int x){
	ll last=1;
	for(int i=1;i<=x;i++) last*=i;
	return last;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
//		cnt+=(c[i]==0);
	}
	for(int i=0;i<n;i++) if(s[i]=='0') f=false;
	if(f) cout<<fact(n);
	return 0;
}
