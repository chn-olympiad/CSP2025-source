#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+6;
struct node{
	int a,b,c;//对应a组，b组，c组 
};
node a[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
bool cmp3(node x,node y){
	return x.c>y.c; 
}
int sum[N],n;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a >> a[i].b >> a[i].c;	
		}
		sort(a+1,a+n+1,cmp);
		sort(a+1,a+n+1,cmp2);
		sort(a+1,a+n+1,cmp3);
		int ans=0;
		for(int i=1;i<=n;i++){
			sum[i]=a[i].a+a[i].b+a[i].c;
			ans+=sum[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
