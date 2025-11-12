#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,dp[N],a1,b1,c1,ans;
struct Node{
	int a,b,c,s;
}f[N];
bool cmp(Node s1,Node s2){
	return s1.a>s2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
		}
		if(n==2){
			a1=max(f[0].a+f[1].b,f[0].a+f[1].c);
			b1=max(f[0].b+f[1].a,f[0].b+f[1].c);
			c1=max(f[0].c+f[1].a,f[0].c+f[1].b);
			cout<<max(max(a1,b1),c1)<<endl;
		}else{
			sort(f,f+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=f[i].a;
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
