#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,num[505],s1;
long long sum=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s1=s.size();
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			s1=i+1;
			break;
		}
	}
	if(s1==m){
		for(long long i=n;i>1;i--){
			sum=(sum*i)%MOD;
		}
		cout<<sum;
	}
	else{
		cout<<0;
	}
	return 0;
}//20
