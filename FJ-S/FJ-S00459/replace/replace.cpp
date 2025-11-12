#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
struct jgt{
	int k,v,siz;
};
int n,q,siza,sizb,fa,fb,t,qq;
string sa,sc;
jgt a[N];
int p;
bool cmp(jgt x,jgt y){
	if(x.k!=y.k) return x.k<y.k;
	else if(x.siz!=y.siz) return x.v<y.v;
	return x.siz<y.siz;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa>>sc;
		fa=0,fb=0,t=0;
		a[i].siz=sa.size();
		while(fa==0||fb==0){
			if(sa[t]=='b'){
				fa=1;
				siza=t;
			}
			if(sc[t]=='b'){
				fb=1;
				sizb=t;
			}
			t++;
		}
		a[i].v=abs(siza-sizb);
		if(siza<sizb) a[i].k=1;
		else a[i].k=2;
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].k==1) l=mid+1;
		else r=mid-1;
	}
	qq=l;
	for(int i=1;i<=q;i++){
		cin>>sa>>sc;
		fa=0,fb=0,t=0;
		while(fa==0||fb==0){
			if(sa[t]=='b'){
				fa=1;
				siza=t;
			}
			if(sc[t]=='b'){
				fb=1;
				sizb=t;
			}
			t++;
		}
		p=abs(siza-sizb);
		if(siza<sizb) l=1,r=qq-1;
		else l=qq,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid].v>p||a[mid].siz>sa.size()) r=mid-1;
			else l=mid+1;
		}
		if(a[l].v>p||a[l].siz>sa.size()) l--;
		if(siza<sizb) cout<<l<<"\n";
		else cout<<l-qq+1<<"\n";
	}
	return 0;
}
