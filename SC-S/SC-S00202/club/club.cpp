#include<bits/stdc++.h>
using namespace std;
int const N=114514;
int t,n;
vector<int> c[4];
struct member{
	int b[4],m1,m2,m3,id;
}a[N];
int vis[N];
void init(){
//	for(int i=0;i<=3;i++){
//		for(int j=0;j<=n;j++) c[i].push_back(0);
//	}
	for(int i=1;i<=n;i++){
		a[i].m1=1;
		a[i].m3=3;
		a[i].id=i;
		vis[i]=i;
		if(a[i].b[2]>a[i].b[a[i].m1]) a[i].m1=2;
		if(a[i].b[2]<a[i].b[a[i].m3]) a[i].m3=2;
		if(a[i].b[3]>a[i].b[a[i].m1]) a[i].m1=3;
		if(a[i].b[1]<a[i].b[a[i].m3]) a[i].m3=1;
		a[i].m2=6-a[i].m1-a[i].m3;
//		printf("%d  %d %d %d  %d %d %d\n",a[i].id,a[i].m1,a[i].m2,a[i].m3,a[i].b[a[i].m1],a[i].b[a[i].m2],a[i].b[a[i].m3]);
	}
//	cout<<'\n';
}
bool cmp(int x,int y){
	int p=vis[x],q=vis[y];
	int p1=a[p].m1,p2=a[p].m2,p3=a[p].m3;
	int q1=a[q].m1,q2=a[q].m2,q3=a[q].m3;
	if(a[p].b[p1]==a[q].b[q1]){
		if(a[p].b[p2]==a[q].b[q2]){
			if(a[p].b[p3]==a[q].b[q3]) return a[p].id<a[q].id;
			else return a[p].b[p3]>a[q].b[q3];
		}
		else return a[p].b[p2]>a[q].b[q2];
	}
	else return a[p].b[p1]>a[q].b[q1];
}
int ans(){
	int ret=0;
	for(int i=1;i<=3;i++){
		while(!c[i].empty()){
			ret+=c[i][c[i].size()-1];
			c[i].pop_back();
		}
	}
	return ret;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
//	for(int i=1;i<=n;i++) printf("%d  %d %d %d\n",i,a[i].b[1],a[i].b[2],a[i].b[3]);
//	cout<<'\n';
	init();
	sort(vis+1,vis+n+1,cmp);
	for(int i=1;i<=n;i++){
		int p=vis[i];
		int q1=a[p].m1,q2=a[p].m2,q3=a[p].m3;
//		printf("%d  %d %d %d  %d %d %d\n",p,q1,q2,q3,a[p].b[q1],a[p].b[q2],a[p].b[q3]);	
		if(c[q1].size()<=(n/2+1)) c[q1].push_back(a[p].b[q1]);
		else if(c[q2].size()<=(n/2+1)) c[q2].push_back(a[p].b[q2]);
		else c[q3].push_back(a[p].b[q3]);
	}
//	printf("\n%d\n\n\n",ans());
	printf("%d\n",ans());
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}