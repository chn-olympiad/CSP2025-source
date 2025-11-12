#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct st {
	int w,id;
} ;
struct stt {
	int a,b,c;
};
int co[100010];
bool cmp(st x,st y) {
	return x.w>y.w;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int ans=0;
		st a[100010],b[100010],c[100010];
		stt s[100010];
		memset(co,0,sizeof(0));
		cin>>n;
		int l=n/2;
		for(int i=1; i<=n; i++) {
			cin>>a[i].w>>b[i].w>>c[i].w;
			s[i].a=a[i].w;
			s[i].b=b[i].w;
			s[i].c=c[i].w;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
		}
		bool tp=1;
		for(int i=1; i<=n; i++) {
			if(c[i].w!=0) {
				tp=0;
				break;
			}
		}
		if(tp) {
			bool tpp=1;
			for(int i=1; i<=n; i++) {
				if(b[i].w!=0) {
					tpp=0;
					break;
				}
			}
			if(tpp) {
				sort(a+1,a+n+1,cmp);
				for(int i=1; i<=l; i++) {
					ans+=a[i].w;
				}
				cout<<ans<<endl;
				continue;
			} else {
				sort(a+1,a+n+1,cmp);
				sort(b+1,b+n+1,cmp);
				for(int i=1; i<=l; i++) {
					ans+=a[i].w;
					ans+=b[i].w;
				}
				cout<<ans<<endl;
				continue;
			}
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=l; i++) {
			co[a[i].id]=1;
			ans+=a[i].w;
		}
		/*for(int i=1; i<=n; i++) {
			cout<<co[i]<<" ";
		}
		cout<<endl;
		*/
		sort(b+1,b+n+1,cmp);
		for(int i=1; i<=l; i++) {
			if(co[b[i].id]==1) {
				int ma=s[b[i].id].a;
				if(ma<b[i].w) {
					ans-=ma;
					ans+=b[i].w;
					co[b[i].id]=2;
					int l=1,r=n;
					int anss=0;
					while(l<=r) {
						int mid=(l+r)/2;
						if(a[l].w>ma) {
							l=mid+1;
							anss=mid;
						} else {
							r=mid-1;
						}
					}
					for(int j=anss; j<=n; j++) {
						if(co[a[j].id]==0) {
							ans+=a[j].w;
							co[a[j].id]=1;
							break;
						}
					}
				}
			} else {
				co[b[i].id]=2;
				ans+=b[i].w;
			}
		}
		/*for(int i=1; i<=n; i++) {
			cout<<co[i]<<" ";
		}
		cout<<endl;
		*/
		sort(c+1,c+n+1,cmp);
		for(int i=1; i<=l; i++) {
			if(co[c[i].id]!=0) {
				if(co[c[i].id]==1) {
					int ma=s[c[i].id].a;
					if(ma<c[i].w) {
						ans-=ma;
						ans+=c[i].w;
						int l=1,r=n;
						int anss=0;
						while(l<=r) {
							int mid=(l+r)/2;
							if(a[l].w>ma) {
								l=mid+1;
								anss=mid;
							} else {
								r=mid-1;
							}
						}
						for(int j=anss; j<=n; j++) {
							if(co[a[j].id]==0) {
								ans+=a[j].w;
								co[a[j].id]=1;
								break;
							}
						}
					}
				}
				if(co[c[i].id]==2) {
					int ma=s[c[i].id].b;
					if(ma<c[i].w) {
						ans-=ma;
						ans+=c[i].w;
						int l=1,r=n;
						int anss=0;
						while(l<=r) {
							int mid=(l+r)/2;
							if(b[l].w>ma) {
								l=mid+1;
								anss=mid;
							} else {
								r=mid-1;
							}
						}
						for(int j=anss; j<=n; j++) {
							if(co[b[j].id]==0) {
								ans+=b[j].w;
								co[b[j].id]=1;
								break;
							}
						}
					}
				}
			} else {
				co[c[i].id]=3;
				ans+=c[i].w;
			}
		}
		cout<<ans<<endl;
		/*for(int i=1; i<=n; i++) {
			cout<<co[i]<<" ";
		}
		cout<<endl;
		*/
	}
	return 0;
}
