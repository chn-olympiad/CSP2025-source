#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define ull unsigned long long
//#define connect_or_leave_oi return
int n,m;
string s;
int c[510];
LL ans=0;
const int mod=998244353;
bool check(vector<int>&x){
	int los=0,ge=0;
	for(int i=0;i<n;i++){
		if(los>=c[x[i]]){
			los++;
			continue;
		}
		if(s[i]=='0')los++;
		else ge++;
		if(ge>=m)return 1;
	}
	return ge>=m;
}
void tsxz(){
	LL ans=1;
	for(int i=1;i<=n;i++){
		ans*=i%mod;
		ans%=mod;
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	//dfs(1);
	vector<int>k;
	string ppp;
	for(int i=0;i<s.size();i++)ppp.push_back('1');
	if(ppp==s){
		tsxz();
		return 0;
	}
	for(int i=1;i<=n;i++)k.push_back(i);
	do{
		ans+=check(k);ans%=mod;
	}while(next_permutation(k.begin(),k.end()));
	cout<<ans;
	//connect_or_leave_oi 0;
	return 0;
}
