#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,ma,d;
}t[100009];
bool zcmp(node i,node j){
	return i.ma>j.ma;
}
bool cmp(int i,int j){
	return i<j;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int a[100009],b[100009],c[100009],cnta=0,cntb=0,cntc=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&t[i].a,&t[i].b,&t[i].c);
			t[i].ma=max(t[i].a,max(t[i].b,t[i].c));
			if(t[i].a==t[i].ma){
				t[i].d=t[i].ma-max(t[i].b,t[i].c);
			}
			if(t[i].b==t[i].ma){
				t[i].d=t[i].ma-max(t[i].a,t[i].c);
			}
			if(t[i].c==t[i].ma){
				t[i].d=t[i].ma-max(t[i].a,t[i].b);
			}
		}
		int ans=0;
		sort(t+1,t+1+n,zcmp);
		for(int i=1;i<=n;i++){
			if(t[i].a==t[i].ma){
				a[++cnta]=t[i].d;
				ans+=t[i].ma;
			}
			else if(t[i].b==t[i].ma){
				b[++cntb]=t[i].d;
				ans+=t[i].ma;
			}
			else if(t[i].c==t[i].ma){
				c[++cntc]=t[i].d;
				ans+=t[i].ma;
			}
		}
		sort(a+1,a+cnta+1,cmp);
		sort(b+1,b+cntb+1,cmp);
		sort(c+1,c+cntc+1,cmp);
		int i=1;
		while(cnta*2>n){
			cnta--;
			ans-=a[i];
			i++;
		}
		while(cntb*2>n){
			cntb--;
			ans-=b[i];
			i++;
		}
		while(cntc*2>n){
			cntc--;
			ans-=c[i];
			i++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
