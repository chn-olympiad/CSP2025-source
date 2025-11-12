#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
struct node{
	int a,b,c;
}a[N];
bool cmp(node a,node b){
	if(min(a.a-a.b,a.a-a.c)!=min(b.a-b.b,b.a-b.c)){
		return min(a.a-a.b,a.a-a.c)>min(b.a-b.b,b.a-b.c);		
	}else{
		return a.a>b.a;
	}
}
bool cmp2(node a,node b){
	return a.b-a.c>b.b-b.c;
}
bool cmp3(node a,node b){
	return a.a-a.b>b.a-b.b;
}
void work(int n){
	sort(a+1,a+n+1,cmp3);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=a[i].b;
	}	
	printf("%d\n",ans);
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
	int flg=1;
	for(int i=1;i<=n;i++) if(a[i].c!=0) flg=0;
	if(flg){
		work(n);
		return;
	}
	sort(a+1,a+n+1,cmp);
	int i=1,cnt=0,ans=0;
	for(;i<=n/2 && min(a[i].a-a[i].b,a[i].a-a[i].c)>=0;i++){	
		ans+=a[i].a;
	}
	sort(a+i,a+n+1,cmp2);
	for(;i<=n && ++cnt<=n/2 && a[i].b-a[i].c>=0;i++){
		ans+=a[i].b;
	}	
	for(;i<=n;i++){
		ans+=a[i].c;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
