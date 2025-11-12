#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node{
	long long x;
	long long y;
	long long z;
	int flag;
	long long bh;
}q[N];
//bool cmp(node x,node y){
//	return x.x+x.y+x.z>y.x+y.y+y.z;
//}
//int pd(node p){
//	if(p.x>=p.y&&p.x>=p.z)return 1;
//	if(p.y>=p.z&&p.y>=p.x)return 2;
//	if(p.z>=p.x&&p.z>=p.y)return 3;
//}
struct mode{
	int v;
	int bh;
}a[N];
mode b[N];
mode c[N];
//int pd(node p){
//	int a = p.x-p.y;
//	int b = p.y-p.z;
//	int c = p.x-p.z;
//	if()return 1;
//	if(b>-1*c)return 2;
//	if()
//}
bool cmp(mode x,mode y){
	return x.v > y.v;
}
int main(){
	freopen("club2.in","r",stdin);
	freopen("club2.out","w",stdout);
	long long n;
	long long t;
	scanf("%d",&t);
	while(t--){
		long long ans = 0;
		long long bm1 = 0,bm2 = 0,bm3 = 0;
		long long ans1 = 0,ans2 = 0,ans3 = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>q[i].x>>q[i].y>>q[i].z;
			q[i].bh = i;
			a[i].v  =q[i].x;
			b[i].v = q[i].y;
			c[i].v = q[i].z;
			a[i].bh = i;
			b[i].bh = i;
			c[i].bh = i;
			q[i].flag = 0;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].v>=q[a[i].bh].y&&a[i].v>=q[a[i].bh].z&&q[a[i].bh].flag==0&&ans1<n/2){
				ans+=a[i].v;
				q[a[i].bh].flag = 1;
				ans1++; 
			}
			if(b[i].v>=q[b[i].bh].z&&b[i].v>=q[b[i].bh].x&&q[b[i].bh].flag==0&&ans2<n/2){
				ans+=b[i].v;
				q[b[i].bh].flag = 1;
				ans2++;
			}
			if(c[i].v>=q[c[i].bh].x&&c[i].v>=q[c[i].bh].y&&q[c[i].bh].flag==0&&ans3<n/2){
				ans+=c[i].v;
				q[c[i].bh].flag = 1;
				ans3++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
