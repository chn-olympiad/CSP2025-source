#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,v[N],t;
struct E{
	int f,s,t,i1;
}a[N];
int cmp(E a,E d){
	if(a.f!=d.f) return a.f>d.f;
	if(a.s!=d.s ) return a.s<d.s;
	return a.t<d.t;
}
int cmp1(E a,E d){
	if(a.s!=d.s ) return a.s>d.s;
	if(a.t!=d.t ) return a.t<d.t;
	return a.f<d.f;	
}
int cmp2(E a,E d){
	if(a.t!=d.t ) return a.t>d.t;
	if(a.s!=d.s ) return a.s<d.s;
	return a.f<d.f;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0;
		cin>>n;
		int cnt=n/2+1,anss=0;
		for(int i=1;i<=n;i++){
			v[i]=0;
			a[i].i1=i;
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		sort(a+1,a+1+n,cmp);
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(a[i].f>=max(a[i].s,a[i].t)){
				cntt++;
				ans+=a[i].f;
				v[a[i].i1]=1;
			}
			if(cntt+1>=cnt)break;
		}
//		cout<<ans<<" "<<cntt<<"\n";
		anss+=cntt,cntt=0;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(!v[a[i].i1]&&a[i].s>=max(a[i].f,a[i].t)){
				cntt++;
				ans+=a[i].s;
				v[a[i].i1]=1;
			}
			if(cntt+1>=cnt)break;
		}
//		cout<<ans<<" "<<cntt<<"\n";
		anss+=cntt,cntt=0;
		if(anss==n){
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(!v[a[i].i1]&&a[i].t>=max(a[i].f,a[i].s)){
				cntt++;
				ans+=a[i].t;
				v[a[i].i1]=1;
			}
			if(cntt+1>=cnt)break;
		}
		cout<<ans<<"\n";		
	}
	return 0;
}
