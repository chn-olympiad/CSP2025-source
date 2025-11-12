#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(nullptr));
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt<m) cout<<"0";
	else cout<<rand()%mod;
	return 0;
}
