#include <iostream>
#include <algorithm>
#define int long long 
using namespace std;
int t;
int n;
struct p
{
	int id1,id2,x1,x2,x3;//4:x,y 5:y,z 6:x,z
}r[100005];
int _max=0;
bool cmp(p p1,p p2)
{
	if (p1.x3==p2.x3){
		return p1.id1<p2.id1;
	}
	return p1.x3<p2.x3;
}
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while (c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(int)(c-'0');
		c=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while (t--){
		n=read();
		int x,y,z;
		int tot=0,ans=0;
		for (int i=1; i<=n; i++){
			x=read(),y=read(),z=read();
			_max=max(x,max(y,z));
			if (x==y || y==z || x==z){
				if (x==y){
					if (x==z){
						ans+=x;
						r[i].id1=r[i].id2=0;
						continue;
					}
					if (z>x){
						r[i].id1=3,r[i].id2=4;
						r[i].x1=z,r[i].x2=x;
					}
					else {
						r[i].id1=4,r[i].id2=3;
						r[i].x1=x,r[i].x2=z;
					}
				}
				else {
					if (y==z){
						if (z>x){
							r[i].id1=5,r[i].id2=1;
							r[i].x1=z,r[i].x2=x;
						}
						else {
							r[i].id1=1,r[i].id2=5;
							r[i].x1=x,r[i].x2=z;
						}
					}
					else {
						if (z>y){
							r[i].id1=6,r[i].id2=2;
							r[i].x1=z,r[i].x2=y;
						}
						else {
							r[i].id1=2,r[i].id2=6;
							r[i].x1=y,r[i].x2=x;
						}
					}
				}
				continue;
			}
			if (x==_max){
				r[i].id1=1,r[i].x1=x;
				if (y>z){
					r[i].id2=2,r[i].x2=y;
				}
				else {
					r[i].id2=3,r[i].x2=z;
				}
			}
			else {
				if (y==_max){
					r[i].id1=2,r[i].x1=y;
					if (x>z){
						r[i].id2=1,r[i].x2=x;
					}
					else {
						r[i].id2=3,r[i].x2=z;
					}
				}
				else {
					if (z==_max){
						r[i].id1=3,r[i].x1=z;
						if (y>x){
							r[i].id2=2,r[i].x2=y;
						}
						else {
							r[i].id2=1,r[i].x2=x;
						}
					}
				}
			}
		}
		int tot1=0,tot2=0,tot3=0;
		for (int i=1; i<=n; i++){
			if (r[i].id1!=0 && r[i].id2!=0){
				r[i].x3=r[i].x1-r[i].x2;
			}
			if (r[i].id1==1 || r[i].id1==4 || r[i].id1==6){
				tot1++;
			}
			if (r[i].id1==2 || r[i].id1==4 || r[i].id1==5){
				tot2++;
			}
			if (r[i].id1==3 || r[i].id1==5 || r[i].id1==6){
				tot3++;
			}
		}
//		for (int i=1; i<=n; i++){
//			cout<<r[i].id1<<" "<<r[i].id2<<" "<<r[i].x1<<" "<<r[i].x2<<endl;
//		}
		if (tot1>n/2){
			sort(r+1,r+n+1,cmp);
			int cnt=0;
			for (int i=1; i<=n; i++){
				if (r[i].id1==1 && cnt<tot1-n/2){
					ans+=r[i].x2;
					cnt++;
				}
				else {
					ans+=r[i].x1; 
				}
			}
		}
		if (tot2>n/2){
			sort(r+1,r+n+1,cmp);
			int cnt=0;
			for (int i=1; i<=n; i++){
				if (r[i].id1==2 && cnt<tot2-n/2){
					ans+=r[i].x2;
					cnt++;
				}
				else {
					ans+=r[i].x1; 
				}
			}
		}
		if (tot3>n/2){
			sort(r+1,r+n+1,cmp);
			int cnt=0;
			for (int i=1; i<=n; i++){
				if (r[i].id1==3 && cnt<tot3-n/2){
					ans+=r[i].x2;
					cnt++;
				}
				else {
					ans+=r[i].x1; 
				}
			}
		}
		if (tot1<=n/2 && tot2<=n/2 && tot3<=n/2){
			sort(r+1,r+n+1,cmp);
			for (int i=1; i<=n; i++){
				if (r[i].id1!=0 && r[i].id2!=0){
					ans+=r[i].x1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
