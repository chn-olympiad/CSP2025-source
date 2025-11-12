#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,T;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&T);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(T--){
		string a,b;
		cin>>a>>b;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			ll x=a.find(s1[i]);
			if(x<0||x>=a.size())continue;
			string c=a;
			c.replace(x,s1[i].size(),s2[i]);
			if(c==b)cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
