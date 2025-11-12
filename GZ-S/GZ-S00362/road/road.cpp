//GZ-S00362 北京师范大学贵阳附属中学 罗思妤
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100;
long long n,m,k,t[15],cnt,sum,mi,ma,l;
struct Node{
	long long x,y,z;
}a[N];
bool f[N];
bool cmp (Node x,Node y){
	return x.z<y.z;
}
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	scanf ("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf ("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		ma=max(ma,a[i].z);
	}
	for (int i=1;i<=k;i++){
		scanf ("%lld",&t[i]);
		mi=INT_MAX;
		for (int j=1;j<=n;j++){
			l++;
			scanf ("%lld",&a[m+l].z);
			mi=min(mi,a[m+l].z);
			a[m+l].x=i+n;
			a[m+l].y=j;
		}
		if (mi+t[i]>ma){
			l-=m;
			t[i]=0;
		}
	}
	sort (a+1,a+1+m+l,cmp);
	for (int i=1,j;j<=k,i<=m+l;i++){
		if (t[a[i].x-m]>0){
			a[i].z+=t[a[i].x-n];
			t[a[i].x-n]=0;
			j++;
		}
		if (t[a[i].y-m]>0){
			a[i].z+=t[a[i].y-n];
			t[a[i].y-n]=0;
			j++;
		}
	}
	sort (a+1,a+1+m+l,cmp);
	for (int i=1;i<=m+l || cnt<=n;i++){
		if (f[a[i].x]==0 || f[a[i].y]==0){
			sum+=a[i].z;
			if (f[a[i].x]==0){
				f[a[i].x]=1;
				cnt++;
			}
			if (f[a[i].y]==0){
				f[a[i].y]=1;
				cnt++;
			}
		}
	}
	printf ("%lld",sum);
	return 0;
}
