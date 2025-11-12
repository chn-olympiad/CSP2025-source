#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=998244353;
vector<int> p;
bool x(string s){
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='0') return false;
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	string s;
	int a[1005];
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>s;
	if(x(s)){
		ll mvp=1;
		for(ll i=1;i<=n;i++){
			mvp=(mvp+n-i)%N;
		}
		cout<<mvp<<endl;
		return 0;
	}
	return 0;
}
//终于比完了^-^(我完了) 
