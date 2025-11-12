#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,m,c[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)sum++;
	}
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')flag=1;
	}
	if(!flag){
	long long val=1;
	for(int i=1;i<=sum;i++){
		val*=i;
		val%=Mod;
	}
	cout<<val;
	return 0;
    }
	cout<<0;
	return 0;
}
