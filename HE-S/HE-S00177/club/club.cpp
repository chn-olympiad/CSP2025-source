#include<bits/stdc++.h>
using namespace std;
int T;
int n,f[4],ans,ans1;
struct node{
	int a,b,c,x,mx,mxi,nmx,nmxi;
}a[100010];
inline bool cmp(node a,node b){
	return (a.x==b.x?a.mx>b.mx:a.x>b.x);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		f[1]=f[2]=f[3]=ans=ans1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].mx=a[i].a;
				a[i].mxi=1;
				if(a[i].b>a[i].c)a[i].x=a[i].a-a[i].b,a[i].nmx=a[i].b,a[i].nmxi=2;
				else a[i].x=a[i].a-a[i].c,a[i].nmx=a[i].c,a[i].nmxi=3;
				
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				a[i].mx=a[i].b;
				a[i].mxi=2;
				if(a[i].a>a[i].c)a[i].x=a[i].b-a[i].a,a[i].nmx=a[i].a,a[i].nmxi=1;
				else a[i].x=a[i].b-a[i].c,a[i].nmx=a[i].c,a[i].nmxi=3;
			}else{
				a[i].mx=a[i].c;
				a[i].mxi=3;
				if(a[i].a>a[i].b)a[i].x=a[i].c-a[i].a,a[i].nmx=a[i].a,a[i].nmxi=1;
				else a[i].x=a[i].c-a[i].b,a[i].nmx=a[i].b,a[i].nmxi=2;
			}
			
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
//			cout<<a[i].mxi<<' '<<a[i].nmxi<<endl;
			if(f[a[i].mxi]<n/2)ans+=a[i].mx,f[a[i].mxi]++;
			else ans+=a[i].nmx,f[a[i].nmxi]++;
		}printf("%d\n",ans);
//		puts("");
	}
	return 0;
}
