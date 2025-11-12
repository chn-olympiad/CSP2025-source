#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,ta,tb,tc;
struct Node{
	long long s,val;
}a[100010],b[100010],c[100010];
bool cmp(Node a,Node b){
	return a.val<b.val;
}	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=ta=tb=tc=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].s,&b[i].s,&c[i].s);
			if(max(max(a[i].s,b[i].s),c[i].s)==a[i].s){
				ans+=a[i].s,ta++;
				if(b[i].s>c[i].s){a[i].val=a[i].s-b[i].s;b[i].val=b[i].s-c[i].s;}
				else{a[i].val=a[i].s-c[i].s;c[i].val=c[i].s-b[i].s;}
			}
			else if(max(max(a[i].s,b[i].s),c[i].s)==b[i].s){
				ans+=b[i].s,tb++;
				if(a[i].s>c[i].s){b[i].val=b[i].s-a[i].s;a[i].val=a[i].s-c[i].s;}
				else{b[i].val=b[i].s-c[i].s;c[i].val=c[i].s-a[i].s;}
			}
			else if(max(max(a[i].s,b[i].s),c[i].s)==c[i].s){
				ans+=c[i].s,tc++;
				if(a[i].s>b[i].s){c[i].val=c[i].s-a[i].s;a[i].val=a[i].s-b[i].s;}
				else{c[i].val=c[i].s-b[i].s;b[i].val=b[i].s-a[i].s;}
			}
	 	}
	 	sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=ta-n/2;i++)ans-=a[i].val;
		for(int i=1;i<=tb-n/2;i++)ans-=b[i].val;
		for(int i=1;i<=tc-n/2;i++)ans-=c[i].val;
		printf("%lld\n",ans);
	}
	return 0;
}
