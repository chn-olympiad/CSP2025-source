#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int T;
int n;
int ans=0;
struct nmd{
	int a,b,c,d;
}a[N];
int cmp(nmd a,nmd b){
	return a.d>b.d;
}
int la=0,lb=0;
int main( ){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		la=0;
		lb=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=abs(a[i].a-a[i].b);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b&&la<n/2){
				la++;
				ans+=a[i].a;
			} else if(a[i].a<a[i].b&&lb<n/2){
				lb++;
				ans+=a[i].b;
			} else if(la==n/2){
				lb++;
				ans+=a[i].b;
			}
			else {
				la++;
				ans+=a[i].a;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

