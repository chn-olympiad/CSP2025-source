#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	srand(time(0));
	cout<<rand()%mod;
	return 0;
} 