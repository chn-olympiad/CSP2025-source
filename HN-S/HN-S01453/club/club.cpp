#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e5+1;
struct jgt{
	int a,b,c;
}an[N];
bool cmp(jgt a,jgt b){
	return a.a>b.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>an[i].a>>an[i].b>>an[i].c;
		sort(an+1,an+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=an[i].a;
		cout<<ans<<"\n";
	}
	return 0;
}
