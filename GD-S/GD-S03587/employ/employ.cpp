#include<bits/stdc++.h> 
#define ll long long
using namespace std;
int n,m,t,c[20005],sum,a[20005],k,ui,vi,wi;
ll ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%lld",ans);
	return 0;
}
