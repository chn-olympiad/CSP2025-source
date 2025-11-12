#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
struct node{
	int v1,v2,v3;
};
bool cmp1(node x,node y){
	return x.v1>y.v1;
}
bool cmp2(node x,node y){
	return x.v2>y.v2;
}
bool cmp3(node x,node y){
	return x.v3>y.v3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		node a[100005];
		int b[100005],c[100005],d[100005],ans=0,f1,f2,f3,f=0;
		f1=n/2;
		f2=n/2;
		f3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
			if(a[i].v2!=0||a[i].v3!=0){
				f=1;
			}
		}
		if(n==2){
			ans=max(a[1].v1+a[2].v2,max(a[1].v1+a[2].v3,max(a[1].v2+a[2].v1,max(a[1].v2+a[2].v3,max(a[1].v3+a[2].v1,a[1].v3+a[2].v2)))));
			cout<<ans<<endl;
			continue;
		}
		if(f==0){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=(n/2);i++){
				ans+=a[i].v1;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			b[i]=a[i].v1;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			c[i]=a[i].v2;
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++){
			d[i]=a[i].v3;
		}
		for(int i=1;i<=n;i++){
			int maxx=max(b[i],max(c[i],d[i]));
			if(b[i]==c[i]&&b[i]==d[i]){
				ans+=maxx;
				maxx=max(b[i+1],max(c[i+1],d[i+1]));
				if(maxx==b[i+1]){
					f1--;
				}else if(maxx==c[i+1]){
					f2--;
				}else {
					f3--;
				}
			}
			if(maxx==b[i]&&f1>0){
				if(b[i]==c[i]&&b[i]!=d[i]){
					if(b[i+1]>=c[i+1]){
						f1--;
						ans+=b[i];
					}else if(b[i+1]<c[i]){
						f2--;
						ans+=c[i];
					}
				}else if(b[i]==d[i]&&b[i]!=c[i]){
					if(b[i+1]>=d[i+1]){
						f1--;
						ans+=b[i];
					}else if(b[i+1]<d[i]){
						f2--;
						ans+=d[i];
					}
				}
				f1--;
				ans+=b[i];
			}else if(maxx==c[i]&&f2>0){
				f2--;
				ans+=c[i];
			}else if(maxx==d[i]&&f3>0){
				f3--;
				ans+=d[i];
			}else if(maxx==b[i]&&f1==0){
				maxx=max(c[i],d[i]);
				if(maxx==c[i]&&f2>0){
					f2--;
					ans+=c[i];
				}else if(maxx==d[i]&&f3>0){
					f3--;
					ans+=d[i];
				}else if(maxx==c[i]&&f2==0){
					f3--;
					ans+=d[i];
				}
			}else if(maxx==c[i]&&f2==0){
				maxx=max(b[i],d[i]);
				if(maxx==b[i]&&f1>0){
					f1--;
					ans+=b[i];
				}else if(maxx==d[i]&&f3>0){
					f3--;
					ans+=d[i];
				}else if(maxx==b[i]&&f1==0){
					f3--;
					ans+=d[i];
				}
			}else if(maxx==d[i]&&f3==0){
				maxx=max(c[i],b[i]);
				if(maxx==c[i]&&f2>0){
					f2--;
					ans+=c[i];
				}else if(maxx==b[i]&&f1>0){
					f1--;
					ans+=b[i];
				}else if(maxx==c[i]&&f2==0){
					f1--;
					ans+=b[i];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
