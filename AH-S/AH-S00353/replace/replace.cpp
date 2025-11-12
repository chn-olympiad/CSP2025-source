#include<bits/stdc++.h>
using namespace std;
long long n,q,cnt;
string a[200010],b[200010],s,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(long long i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--){
		cnt=0;
		cin>>s>>y;
		for(long long i=0;i<s.size();i++)
			for(long long j=1;j<=n;j++)
				if(s.size()-i>=a[j].size()&&y.size()-i>=b[j].size()){
					string subs=s.substr(i,a[j].size());
					string suby=y.substr(i,b[j].size());
					string x=s.substr(0,i);
					string z=s.substr(i+a[j].size(),s.size()-i-a[j].size());
					if(subs==a[j]&&suby==b[j]&&x+suby+z==y){
						cnt++;
						break;
					}
				}
		printf("%lld\n",cnt);
	}
	return 0;
}
