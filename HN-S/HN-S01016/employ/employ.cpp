#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5e2+5;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long sum=1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		}
	}
	for(int i=cnt;i<=n;i++){
		sum*=i;
		sum%=MOD;
	}
	cout<<sum%MOD;
	return 0;
} 
