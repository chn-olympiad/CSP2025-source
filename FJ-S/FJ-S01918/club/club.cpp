#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll T,n,sum,t[4],mt=0,cmt=0;
struct node{
	ll c[4];
}a[N];
bool cmp(node a,node b){
	if (a.c[0]==a.c[1] and b.c[0]==b.c[1])return max(a.c[2],a.c[3])-a.c[0]>max(b.c[2],b.c[3])-b.c[0];
	if (a.c[0]==a.c[1] and b.c[0]==b.c[2])return max(a.c[2],a.c[3])-a.c[0]>max(b.c[1],b.c[3])-b.c[0];
	if (a.c[0]==a.c[1] and b.c[0]==b.c[3])return max(a.c[2],a.c[3])-a.c[0]>max(b.c[1],b.c[2])-b.c[0];
	if (a.c[0]==a.c[2] and b.c[0]==b.c[1])return max(a.c[1],a.c[3])-a.c[0]>max(b.c[2],b.c[3])-b.c[0];
	if (a.c[0]==a.c[2] and b.c[0]==b.c[2])return max(a.c[1],a.c[3])-a.c[0]>max(b.c[1],b.c[3])-b.c[0];
	if (a.c[0]==a.c[2] and b.c[0]==b.c[3])return max(a.c[1],a.c[3])-a.c[0]>max(b.c[1],b.c[2])-b.c[0];
	if (a.c[0]==a.c[3] and b.c[0]==b.c[1])return max(a.c[2],a.c[1])-a.c[0]>max(b.c[2],b.c[3])-b.c[0];
	if (a.c[0]==a.c[3] and b.c[0]==b.c[2])return max(a.c[2],a.c[1])-a.c[0]>max(b.c[1],b.c[3])-b.c[0];
	if (a.c[0]==a.c[3] and b.c[0]==b.c[3])return max(a.c[2],a.c[1])-a.c[0]>max(b.c[1],b.c[2])-b.c[0];	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		sum=t[1]=t[2]=t[3]=mt=0;
		scanf("%lld",&n);
		for (ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].c[1],&a[i].c[2],&a[i].c[3]);
			ll tt=max(max(a[i].c[1],a[i].c[2]),a[i].c[3]);
			if (tt==a[i].c[1]){
				t[1]++;a[i].c[0]=a[i].c[1];
			}else if (tt==a[i].c[2]){
				t[2]++;a[i].c[0]=a[i].c[2];
			}else if (tt==a[i].c[3]){
				t[3]++;a[i].c[0]=a[i].c[3];
			}
		}mt=max(max(t[1],t[2]),t[3]);
		if (mt<=n/2){
			for (int i=1;i<=n;i++)sum+=a[i].c[0];
			printf("%lld\n",sum);continue;
		}
		
		for (int i=1;i<=3;i++){
			if (t[i]==mt)cmt=i;
		}
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n and t[cmt]>n/2;i++){
			if (a[i].c[0]==a[i].c[cmt]){
				t[cmt]--;
				if (cmt==1)a[i].c[0]=max(a[i].c[2],a[i].c[3]);
				if (cmt==2)a[i].c[0]=max(a[i].c[1],a[i].c[3]);
				if (cmt==3)a[i].c[0]=max(a[i].c[1],a[i].c[2]);
			}
		}
		for (int i=1;i<=n;i++)sum+=a[i].c[0];
		printf("%lld\n",sum);continue;
	}
	return 0;
}
/*
思路：先不考虑人数限制
	  再分组微调 
*/
