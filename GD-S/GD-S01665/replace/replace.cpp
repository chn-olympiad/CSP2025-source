#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int N=2e5+10;
LL n,q,i,j,k,l,r,ans;
string c[2];
struct U{
	string a,b;
}s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(i=1;i<=q;i++){
		cin>>c[0]>>c[1];
		ans=0;
		for(j=1;j<=n;j++){
			l=c[0].find(s[i].a);
			r=c[1].find(s[i].b);
			ans+=l==r;
		}
		printf("%lld\n",ans);
	}
	return 0; 
}
