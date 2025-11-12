#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long cnt=1;
	for(int i=1;i<=n;i++){
		cnt*=i;
		cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
