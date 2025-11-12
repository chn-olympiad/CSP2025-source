#include <bits/stdc++.h>
using namespace std;
struct T{
	int a,b,c;
}f[200010];
int n;
long long js(int a,int b,int c,long long s,int i){
	long long m=-1;
	if(i==n){
		if(a+1<=n/2) m=max(s+f[i].a,m);
		if(b+1<=n/2) m=max(s+f[i].b,m);
		if(c+1<=n/2) m=max(s+f[i].c,m);
		return m;
	}
	if(a+1<=n/2) m=max(js(a+1,b,c,s+f[i].a,i+1),m);
	if(b+1<=n/2) m=max(js(a,b+1,c,s+f[i].b,i+1),m);
	if(c+1<=n/2) m=max(js(a,b,c+1,s+f[i].c,i+1),m);
	return m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>f[i].a>>f[i].b>>f[i].c;
		cout<<js(0,0,0,0,1)<<endl;
	}
	return 0;
}
