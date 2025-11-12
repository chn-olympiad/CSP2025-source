#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long t;
long long n;
struct bbb {
	long long a,b,c;
} a[maxn];
bool cmp1(bbb cc,bbb dd) {
	return cc.a>dd.a;
}
bool cmp3(bbb cc,bbb dd) {
	return cc.b>dd.b;
}
bool cmp2(bbb ee,bbb ff) {
	if(ee.a!=ff.a){
		return ee.a>ff.a;
	}else{
		return ee.b>ff.b;
	}
	
}
int aa() {
	for(int i=1; i<=n; i++) {
		if(a[i].b!=0 or a[i].c!=0) {
			return 1;
		}
	}
	sort(a+1,a+n+1,cmp1);
	long long sum=0;
	for(int i=1; i<=n/2; i++) {
		sum+=a[i].a;

	}
	cout<<sum;
	return 0;
}
long long bb() {
	for(int i=1; i<=n; i++) {
		if(a[i].c!=0) {
			return 1;
		}
	}
	long long sa=0,sb=0,sz,zzzz[maxn],sum=0;
	bbb aaaa[maxn],bbbb[maxn];
	for(int i=1;i<=n;i++){
		if(a[i].a>a[i].b){
			sa++;
			aaaa[sa].a=a[i].a;
			aaaa[sa].b=a[i].b;
		}else if(a[i].a<a[i].b){
			sb++;
			bbbb[sb].b=a[i].b;
			bbbb[sb].a=a[i].a;
		}else{
			sz++;
			zzzz[sz]=a[i].a;
			
		}
	}
	if(sa>sb){
		if(sz>=(sa-sb)){
			for(int i=1;i<=sa;i++){
				sum+=aaaa[i].a;
			}
			for(int i=1;i<=sb;i++){
				sum+=bbbb[i].b;
			}
			for(int i=1;i<=sz;i++){
				sum+=zzzz[i];
			}
			cout<<sum;
			return 0;
		}else{
			long long cha=sa-(sb+sz);
			sort(aaaa+1,aaaa+n+1,cmp1);
			for(int i=1;i<=cha;i++){
				sum+=aaaa[i].b;
				aaaa[i].a=0;
			}
			for(int i=1;i<=sa;i++){
				sum+=aaaa[i].a;
			}
			for(int i=1;i<=sb;i++){
				sum+=bbbb[i].b;
			}
			for(int i=1;i<=sz;i++){
				sum+=zzzz[i];
			}
			cout<<sum;
			return 0;
			
		}
	}
	
	if(sa==sb){
		for(int i=1;i<=sa;i++){
				sum+=aaaa[i].a;
			}
			for(int i=1;i<=sb;i++){
				sum+=bbbb[i].b;
			}
			for(int i=1;i<=sz;i++){
				sum+=zzzz[i];
			}
			cout<<sum;
			return 0;
	}
	
	if(sb>sa){
		if(sz>=(sb-sa)){
			for(int i=1;i<=sa;i++){
				sum+=aaaa[i].a;
			}
			for(int i=1;i<=sb;i++){
				sum+=bbbb[i].b;
			}
			for(int i=1;i<=sz;i++){
				sum+=zzzz[i];
			}
			cout<<sum;
			return 0;
		}else{
			long long cha=sb-(sa+sz);
			sort(bbbb+1,bbbb+n+1,cmp2);
			for(int i=1;i<=cha;i++){
				sum+=bbbb[i].a;
				bbbb[i].b=0;
			}
			for(int i=1;i<=sa;i++){
				sum+=aaaa[i].a;
			}
			for(int i=1;i<=sb;i++){
				sum+=bbbb[i].b;
			}
			for(int i=1;i<=sz;i++){
				sum+=zzzz[i];
			}
			cout<<sum;
			return 0;
			
		}
	}

	
}
void qk() {
	for(int i=1; i<=n; i++) {
		a[i].a=0;
		a[i].b=0;
		a[i].c=0;
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		long long sum;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if(aa()==0) continue;
		for(int i=1;i<=n;i++){
			sum+=max(a[i].a,max(a[i].b,a[i].c));
		}
		cout<<sum;
		qk();
	}
	return 0;
}
