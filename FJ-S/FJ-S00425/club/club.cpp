#include<bits/stdc++.h>
using namespace std;
int T,n,zd,A1,A2,A3,ans=0,sum=0;
struct V {
	int x,y,z,id;
} a[100010],b[100010],c[100010],d[100010];
bool cmp(V a,V b) {
	if(a.x!=b.x)
		return a.x>b.x;
	if(a.y!=b.y)
		return a.y>b.y;
	return a.z>b.z;
}
bool cmp1(V a,V b) {
	if(a.x!=b.x)return a.x>b.x;
	return a.id>b.id;
}
bool cmp2(V a,V b) {
	if(a.y!=b.y)return a.y>b.y;
	return a.id>b.id;
}
bool cmp3(V a,V b) {
	if(a.z!=b.z)return a.z>b.z;
	return a.id>b.id;
}
bool cmp4(V a,V b) {
	if(a.x!=b.x)return a.x<b.x;
	return a.id>b.id;
}
bool cmp5(V a,V b) {
	if(a.y!=b.y)return a.y<b.y;
	return a.id>b.id;
}
bool cmp6(V a,V b) {
	if(a.z!=b.z)return a.z<b.z;
	return a.id>b.id;
}
bool cmp7(V a,V b) {
	if(a.x!=b.x)return a.x<b.x;
	return a.id<b.id;
}
bool cmp8(V a,V b) {
	if(a.y!=b.y)return a.y<b.y;
	return a.id<b.id;
}
bool cmp9(V a,V b) {
	if(a.z!=b.z)return a.z<b.z;
	return a.id<b.id;
}
bool cmp10(V a,V b) {
	if(a.x!=b.x)return a.x>b.x;
	return a.id<b.id;
}
bool cmp11(V a,V b) {
	if(a.y!=b.y)return a.y>b.y;
	return a.id<b.id;
}
bool cmp12(V a,V b) {
	if(a.z!=b.z)return a.z>b.z;
	return a.id<b.id;
}
int main() {
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		sum=0;
		zd=n/2;
		for(int i=1; i<=n; i++)cin>>a[i].x>>a[i].y>>a[i].z;
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
		if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}
		}
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
		if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp5);
		sort(d+1,d+1+n,cmp6);
		for(int i=1; i<=n; i++) {
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp5);
		sort(d+1,d+1+n,cmp9);
		for(int i=1; i<=n; i++) {
		if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp5);
		sort(d+1,d+1+n,cmp12);
		for(int i=1; i<=n; i++) {
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}
		}
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp8);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp4);
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		for(int i=1; i<=n; i++) {
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}
		}
		sum=max(sum,ans);
		ans=A1=A2=A3=0;
		for(int i=1;i<=n;i++){
			a[i].id=i,b[i].id=i,c[i].id=i,d[i].id=i;
			b[i].x=a[i].x,c[i].y=a[i].y,d[i].z=a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp4);
		sort(c+1,c+1+n,cmp5);
		sort(d+1,d+1+n,cmp6);
		for(int i=1; i<=n; i++) {
		if(d[i].id!=0&&A3<zd) {
				A3++;
				ans+=d[i].z;
				for(int j=1; j<=n; j++)if(c[j].id==d[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(b[j].id==d[i].id) {
						b[j].id=0;
						break;
					}
				d[i].id=0;
			}else
			if(c[i].y>=d[i].z&&c[i].id!=0&&A2<zd) {
				ans+=c[i].y;
				A2++;
				for(int j=1; j<=n; j++)if(b[j].id==c[i].id) {
						b[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==c[i].id) {
						d[j].id=0;
						break;
					}
				c[i].id=0;
			}else
			
			if(b[i].x>=c[i].y&&b[i].x>=d[i].z&&b[i].id!=0&&A1<zd) {
				ans+=b[i].x;
				A1++;
				for(int j=1; j<=n; j++)if(c[j].id==b[i].id) {
						c[j].id=0;
						break;
					}
				for(int j=1; j<=n; j++)if(d[j].id==b[i].id) {
						d[j].id=0;
						break;
					}
				b[i].id=0;
			}
		}
		sum=max(sum,ans);
		sum=max(sum,ans);
		cout<<sum<<"\n";
	}
	return 0;
}/*
1
4
0   9 10
10 11 10
2   0  3
8   0  4

*/