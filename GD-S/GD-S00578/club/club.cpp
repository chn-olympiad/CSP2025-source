#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int cnt[5];
struct node{
	int a,b,c,max1,max2,k;
}a[N];
bool cmp(node a,node b){
	if(a.max1==b.max1)return a.max2<b.max2;
	return a.max1>b.max1;
}
//bool cmp2(int a,int b)return a>b;
int cha[5][N];
int idx[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		memset(idx,0,sizeof idx);
		memset(cnt,0,sizeof cnt);
		for(int i=1; i<=n; i++){
			a[i].max1=0,a[i].max2=0,a[i].k=0;
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].max1=a[i].a;	
				a[i].max2=max(a[i].b,a[i].c);
				a[i].k=1;
			}
				if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].max1=a[i].b;	
				a[i].max2=max(a[i].a,a[i].c);
				a[i].k=2;
			}
				if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				a[i].max1=a[i].c;	
				a[i].max2=max(a[i].a,a[i].b);
				a[i].k=3;
			}
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		int last1=0,last2=0;
		for(int i=1; i<=n; i++){
			if(cnt[a[i].k]<n/2){
				cnt[a[i].k]++;
				ans+=a[i].max1;
				cha[a[i].k][++idx[a[i].k]]=a[i].max1-a[i].max2;
			}else if(cnt[a[i].k]>=n/2){

				sort(cha[a[i].k]+1,cha[a[i].k]+idx[a[i].k]+1);
				if(cha[a[i].k][1]<a[i].max1-a[i].max2){
					ans=ans-cha[a[i].k][1]+a[i].max1;
					cha[a[i].k][1]=a[i].max1-a[i].max2;
				}else{
					ans+=a[i].max2;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
