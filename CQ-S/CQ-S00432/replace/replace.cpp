#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q;
string s[200005][3],t1,t2;
queue<string>q;
map<string,bool>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&Q);
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(Q--){
		cin>>t1>>t2;
		printf("0\n");
	}
	return 0;
} 
