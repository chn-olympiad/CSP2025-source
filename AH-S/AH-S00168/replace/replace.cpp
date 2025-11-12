#include<bits/stdc++.h>
using namespace std;
string s[200005][2],t1,t2,f;
long long n,q,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		t=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		for(long long i=0;i<t1.size();i++) for(long long j=1;j<=n;j++) if(t1.find(s[j][0])==i){
			f=t1;
			f.erase(i,s[j][0].size());
			f.insert(i,s[j][1]);
			if(f==t2) t++;
		}
		printf("%lld\n",t);
	}
	return 0;
}
