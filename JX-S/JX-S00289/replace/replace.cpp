#include<bits/stdc++.h>
using namespace std;
struct node{
	string s,t;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	while(q--){
		long long ans=0;
		string u,v;
		cin>>u>>v;
		int l=u.length();
		for(int k=0;k<l;k++){
			for(int i=1;i<=n;i++){
				int m=a[i].s.length();
				string o="";
				for(int j=1;j<=m;j++){
					o+=u[k+j-1];
				}
				if(o!=a[i].s)continue;
				string p=u.substr(0,k),q=u.substr(k+m,l-k-m);
				if(p+a[i].t+q==v)ans++;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
