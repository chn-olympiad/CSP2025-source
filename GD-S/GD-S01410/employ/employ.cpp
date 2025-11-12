#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,q;
long long A(int m){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,sum=0;
	cin>>m>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		sum+=s[i]-'0';
	}
	if(sum=n) cout<<A(m);
	else cout<<0;
	return 0;
} 

