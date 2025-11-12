#include <bits/stdc++.h>
using namespace std;
const long long N=100009;
long long t,n,ans;
struct p{
	long long a,b,c;	
};
p m[N],mm[N];
bool cmp2(p x,p y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (long long i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		sort(m+1,m+n+1,cmp2);
		long long num=ceil(n/2.0);			
		for (long long i=1;i<=num;i++) {
			ans+=m[i].a;
		}
		cout<<ans<<endl;
	}
	return 0;
	//5
}
