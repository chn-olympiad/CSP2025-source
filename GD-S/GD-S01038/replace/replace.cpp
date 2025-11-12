#include<bits/stdc++.h>
using namespace std;
struct ns{
	string s1,s2;
}a[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			if(a[i].s1.size()>t1.size()) continue;
			bool f=0;
			for(long long j=0;j<t1.size();j++){
				if(t1[j]!=a[i].s1[0]) continue;
				for(long long k=1;k<=a[i].s1.size();k++){
					string ss=t1.substr(j,k);
					if(ss==a[i].s1){
						string l=t1.substr(0,j); 
						string r=t1.substr(j+k,t1.size()-j-k+1); 
						string nn=l+a[i].s2+r;
						if(nn==t2) {
							ans++;
							f=1;
							break;
						}
					}
				}
				if(f==1) break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
