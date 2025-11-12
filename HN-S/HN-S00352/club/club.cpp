#include<bits/stdc++.h>
using namespace std;
int T,n;
struct kk {
	int a,b,c;
	int maxd=-1,mind=20005;
	int maxh,minh;
	int sum;
} d[100005];
int cmp1(kk q,kk p){
	return q.maxd>p.maxd;
}
int cmp2(kk q,kk p){
	if(q.maxd!=p.maxd) 
		return q.maxd>p.maxd;
	else return q.sum<p.sum;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		int k1=0,k2=0,k3=0,_k1=0,_k2=0,_k3=0;
		int maxxa=-1,maxxb=-1,maxxc=-1;
		for(int i=1; i<=n; i++) {
			cin>>d[i].a>>d[i].b>>d[i].c;
			d[i].maxd=max(d[i].a,max(d[i].b,d[i].c));
			if(d[i].maxd==d[i].a) {
				d[i].maxh=1;
				k1++;
			} else if(d[i].maxd==d[i].b) {
				d[i].maxh=2;
				k2++;
			} else {
				d[i].maxh=3;
				k3++;
			}
			d[i].mind=min(d[i].a,min(d[i].b,d[i].c));
			if(d[i].mind==d[i].a) {
				d[i].minh=1;
				_k1++;
			} else if(d[i].mind==d[i].b) {
				d[i].minh=2;
				_k2++;
			} else {
				d[i].minh=3;
				_k3++;
			}
			d[i].sum=d[i].a+d[i].b+d[i].c;
			maxxa=max(maxxa,d[i].a);
			maxxb=max(maxxb,d[i].b);
			maxxc=max(maxxc,d[i].c);
		}
		if(k1<=n/2&&k2<=n/2&&k3<=n/2) {
			int s=0;
			for(int i=1; i<=n; i++) {
				s+=d[i].maxd;
			}
			cout<<s<<endl;
			continue;	
		} 
		if(maxxa==0&&maxxb==0||maxxc==0&&maxxb==0||maxxa==0&&maxxc==0){
			sort(d+1,d+1+n,cmp1);
			cout<<d[1].maxd+d[2].maxd<<endl;
			continue;
		}
		if(maxxa==0||maxxb==0||maxxc==0){
			sort(d+1,d+1+n,cmp2);
			int ss1=0,ss2=0;
			for(int i=1;i<=n/2;i++){
				ss1+=d[i].maxd;
				ss2+=d[i].sum-d[i].maxd;
			}
			cout<<ss1+ss2;
			continue;
		}
		cout<<maxxa;
	}
	return 0;
}
