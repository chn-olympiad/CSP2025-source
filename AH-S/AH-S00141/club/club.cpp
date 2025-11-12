#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt1,cnt2,cnt3;
struct node{
	int a,b,c;
}p[N],aa[N],bb[N],cc[N];
bool cmp1(node x,node y){
	return (x.a-max(x.b,x.c))>(y.a-max(y.b,y.c));
}
bool cmp2(node x,node y){
	return (x.b-max(x.a,x.c))>(y.b-max(y.a,y.c));
}
bool cmp3(node x,node y){
	return (x.c-max(x.b,x.a))>(y.c-max(y.b,y.a));
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			int u=max(p[i].a,max(p[i].b,p[i].c));
			if(u==p[i].a)aa[++cnt1]=p[i];
			else if(u==p[i].b)bb[++cnt2]=p[i];
			else if(u==p[i].c)cc[++cnt3]=p[i];
		}
		sort(aa+1,aa+cnt1+1,cmp1);
		sort(bb+1,bb+cnt2+1,cmp2);
		sort(cc+1,cc+cnt3+1,cmp3);
		if(cnt1>n/2){
			for(int i=n/2+1;i<=cnt1;i++){
				if(aa[i].b>aa[i].c)bb[++cnt2]=aa[i];
				else cc[++cnt3]=aa[i];
			}
			cnt1=n/2;
		}else if(cnt2>n/2){
			for(int i=n/2+1;i<=cnt2;i++){
				if(bb[i].a>bb[i].c)aa[++cnt1]=bb[i];
				else cc[++cnt3]=bb[i];
			}
			cnt2=n/2;
		}else if(cnt3>n/2){
			for(int i=n/2+1;i<=cnt3;i++){
				if(cc[i].a>cc[i].b)aa[++cnt1]=cc[i];
				else bb[++cnt2]=cc[i];
			}
			cnt3=n/2;
		}
		int ans=0;
		for(int i=1;i<=cnt1;i++)ans+=aa[i].a;
		for(int i=1;i<=cnt2;i++)ans+=bb[i].b;
		for(int i=1;i<=cnt3;i++)ans+=cc[i].c;
		printf("%d\n",ans);
	}
	return 0;
}
