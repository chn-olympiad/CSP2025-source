#include <bits/stdc++.h>
#define For(i,s,e) for(int i=s;i<=e;i++)
#define dFor(i,s,e) for(int i=s;i>=e;i--)
#define int long long
using namespace std;
const int MaxN=1e5+10;
struct node{
	int a,b,c,u;
}a[MaxN];
int t,n,s1,s2,s3,ans,b[MaxN],c[MaxN],d[MaxN];
bool cmp1(int x,int y){
	return min(a[x].a-a[x].b,a[x].a-a[x].c)<min(a[y].a-a[y].b,a[y].a-a[y].c);
}
bool cmp2(int x,int y){
	return min(a[x].b-a[x].a,a[x].b-a[x].c)<min(a[y].b-a[y].a,a[y].b-a[y].c);
}
bool cmp3(int x,int y){
	return min(a[x].c-a[x].a,a[x].c-a[x].b)<min(a[y].c-a[y].a,a[y].c-a[y].b);
}
signed main(){
	//feropen freopn froepon froepen
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		s1=s2=s3=ans=0;
		scanf("%lld",&n);
		For(i,1,n){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b && a[i].a>=a[i].c)a[i].u=1,b[++s1]=i;
			else if(a[i].b>=a[i].a && a[i].b>=a[i].c)a[i].u=2,c[++s2]=i;
			else a[i].u=3,d[++s3]=i;
//			cout<<a[i].c-a[i].a<<endl; 
		}
		if(s1>(n>>1)){
//			cout<<1<<endl;
			sort(b+1,b+s1+1,cmp1);
			for(int i=1;s1-i>=(n>>1);i++){
				a[b[i]].u=a[b[i]].a-a[b[i]].b<a[b[i]].a-a[b[i]].c?2:3;
			}
		}else if(s2>(n>>1)){
//			cout<<2<<endl;
			sort(c+1,c+s2+1,cmp2);
			for(int i=1;s2-i>=(n>>1);i++){
				a[c[i]].u=a[c[i]].b-a[c[i]].a<a[c[i]].b-a[c[i]].c?1:3;
			}
		}else if(s3>(n>>1)){
//			cout<<3<<endl;
			sort(d+1,d+s3+1,cmp3);
//			For(i,1,s3)cout<<a[d[i]].c-a[d[i]].a<<" ";
			for(int i=1;s3-i>=(n>>1);i++){
				a[d[i]].u=a[d[i]].c-a[d[i]].a<a[d[i]].c-a[d[i]].b?1:2;
//				cout<<a[d[i]].u<<endl;
			}
		}
		For(i,1,n){
			ans+=a[i].u==1?a[i].a:(a[i].u==2?a[i].b:a[i].c);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
/*
1
10
18467 14346 18663
11875 7476 12308
13717 11997 15170
13582 4839 15785
13707 2404 17497
3471 2462 8073
13775 8904 19938
6839 5455 15586
8568 3134 18522
11767 12919 2643
*/
