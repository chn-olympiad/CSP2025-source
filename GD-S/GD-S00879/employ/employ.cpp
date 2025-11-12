#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=998244353;
ll n,m,sum=1;
string s;
ll na[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>na[i];
	}
	ll j=1;
	for(int i=1;i<=n;i++){
		if(na[i]==0)continue;
		sum*=j;
		j++;
	}
	cout<<sum%N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

