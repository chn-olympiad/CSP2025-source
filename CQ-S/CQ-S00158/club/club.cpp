#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c,t1,t2,t3;
	node(int x=0,int y=0,int z=0,int q=0,int w=0,int e=0):a(x),b(y),c(z),t1(q),t2(w),t3(e){}
}s[N];
node bd(int a,int b,int c){
	if(a>=b&&b>=c)return node(a,b,c,1,2,3);
	else if(a>=c&&c>=b)return node(a,c,b,1,3,2);
	else if(b>=c&&c>=a)return node(b,c,a,2,3,1);
	else if(b>=a&&a>=c)return node(b,a,c,2,1,3);
	else if(c>=b&&b>=a)return node(c,b,a,3,2,1);
	else if(c>=a&&a>=b)return node(c,a,b,3,1,2);
}
bool cmp(node x,node y){
	if(x.a-x.b==y.a-y.b)return x.b-x.c>y.b-y.c;
	return x.a-x.b>y.a-y.b;
}
int num[4];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			s[i]=bd(a,b,c);
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<4;++i)num[i]=0; 
		for(int i=1;i<=n;++i){
//			printf("%d %d %d %d\n",s[i].a,s[i].b,s[i].t1,s[i].t2);
			if(num[s[i].t1]==n/2){
				ans+=s[i].b;
				num[s[i].t2]++;
			}
			else{
				ans+=s[i].a;
				num[s[i].t1]++;
			}
//			for(int i=1;i<4;++i)printf("%d\n",num[i]);
		}
		printf("%d\n",ans); 
	}
	return 0; 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/ 
