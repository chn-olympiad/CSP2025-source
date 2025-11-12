#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;

struct tup{
	int a,b,c;
}tups[MAXN];

bool cmp1(tup t1,tup t2){
	return t1.a>t2.a;
}

bool cmp2(tup t1,tup t2){
	return t1.b>t2.b;
}

bool cmp3(tup t1,tup t2){
	return t1.c>t2.c;
}

int t;

int n;
int ans;
int cnt1,cnt2,cnt3;

int Max(int a,int b,int c){
	return max(max(a,b),c);
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while (t--){
		ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&tups[i].a,&tups[i].b,&tups[i].c);
		}
		// 分到a 
		sort(tups+1,tups+n+1,cmp1);
		for (int i=1;i<=n/2;i++){
			int a=tups[i].a,b=tups[i].b,c=tups[i].c;
			if (a<max(b,c)||a==-1) break;
			ans+=a;
			tups[i]={-1,-1,-1};
			cnt1++;
		}
		// 分到b 
		sort(tups+1,tups+n+1,cmp2);
		for (int i=1;i<=n/2;i++){
			int a=tups[i].a,b=tups[i].b,c=tups[i].c;
			if (b<max(a,c)||a==-1) break;
			ans+=b;
			tups[i]={-1,-1,-1};
			cnt2++;
		}
		// 分到c
		sort(tups+1,tups+n+1,cmp3);
		for (int i=1;i<=n/2;i++){
			int a=tups[i].a,b=tups[i].b,c=tups[i].c;
			if (c<max(a,b)||a==-1) break;
			ans+=c;
			tups[i]={-1,-1,-1};
			cnt3++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
