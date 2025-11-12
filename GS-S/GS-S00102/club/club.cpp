#include<bits/stdc++.h>
using namespace std;

int T;
int n,maxn,ma,mb,mc,ans;
struct member{
	int a,b,c,maxm,midm,minm,xd,dn;
} m[100005];

bool cmp(member va,member vb){
	return va.maxm>vb.maxm;
}

bool cmp1(member va,member vb){
	return va.xd<vb.xd;
}

bool cmp2(member va,member vb){
	return va.dn<vb.dn;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(m,0,sizeof(0));
		ma=0,mb=0,mc=0,ans=0;
		cin>>n;
		maxn=n/2;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].maxm=max(max(m[i].a,m[i].b),m[i].c);
			m[i].minm=min(min(m[i].a,m[i].b),m[i].c);
			m[i].midm=m[i].a+m[i].b+m[i].c-m[i].maxm-m[i].minm;
			m[i].xd=m[i].maxm-m[i].midm;
			m[i].dn=m[i].midm-m[i].minm;
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n;i++){
			ans+=m[i].maxm;
			if(m[i].maxm==m[i].a){
				ma++;
			}
			else if(m[i].maxm==m[i].b){
				mb++;
			}
			else if(m[i].maxm==m[i].c){
				mc++;
			}
		}
		if(ma>maxn){
			sort(m+1,m+n+1,cmp1);
			for(int i=1;i<=n&&ma>maxn;i++){
				if(m[i].maxm==m[i].a){
					ans-=m[i].xd;
					ma--;
					if(m[i].midm==m[i].b){
						mb++;
					}
					else{
						mc++;
					}
				}
			}
			if(mb>maxn){
				sort(m+1,m+n+1,cmp2);
				for(int i=1;i<=n&&mb>maxn;i++){
					if(m[i].midm==m[i].b&&m[i].minm==m[i].c){
						ans-=m[i].dn;
						mb--;
						mc++;
					}
				}
			}
			if(mc>maxn){
				sort(m+1,m+n+1,cmp2);
				for(int i=1;i<=n&&mc>maxn;i++){
					if(m[i].midm==m[i].c&&m[i].minm==m[i].b){
						ans-=m[i].dn;
						mc--;
						mb++;
					}
				}
			}
		}
		if(mb>maxn){
			sort(m+1,m+n+1,cmp1);
			for(int i=1;i<=n&&mb>maxn;i++){
				if(m[i].maxm==m[i].b){
					ans-=m[i].xd;
					mb--;
					if(m[i].midm==m[i].a){
						ma++;
					}
					else{
						mc++;
					}
				}
			}
			if(ma>maxn){
				sort(m+1,m+n+1,cmp2);
				for(int i=1;i<=n&&ma>maxn;i++){
					if(m[i].midm==m[i].a&&m[i].minm==m[i].c){
						ans-=m[i].dn;
						ma--;
						mc++;
					}
				}
			}
			if(mc>maxn){
				sort(m+1,m+n+1,cmp2);
				for(int i=1;i<=n&&mc>maxn;i++){
					if(m[i].midm==m[i].c&&m[i].minm==m[i].a){
						ans-=m[i].dn;
						mc--;
						ma++;
					}
				}
			}
		}
		if(mc>maxn){
			sort(m+1,m+n+1,cmp1);
			for(int i=1;i<=n&&mc>maxn;i++){
				if(m[i].maxm==m[i].c){
					ans-=m[i].xd;
					mc--;
					if(m[i].midm==m[i].a){
						ma++;
					}
					else{
						mb++;
					}
				}
			}
			if(ma>maxn){
				sort(m+1,m+n+1,cmp2);
				for(int i=1;i<=n&&ma>maxn;i++){
					if(m[i].midm==m[i].a&&m[i].minm==m[i].b){
						ans-=m[i].dn;
						ma--;
						mb++;
					}
				}
			}
			if(mb>maxn){
				sort(m+1,m+n+1,cmp2);
				for(int i=1;i<=n&&mb>maxn;i++){
					if(m[i].midm==m[i].b&&m[i].minm==m[i].a){
						ans-=m[i].dn;
						mb--;
						ma++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
