#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=2e9+10;//?
struct node{
	int w,id;
}a[N][5],s[5];
int c[5][N];
bool cmp(node x,node y){
	return x.w>y.w;
}
void solve(){
	int n;
	cin>>n;
	
	for(int i=1,x,y,z;i<=n;++i){
		cin>>x>>y>>z;
		a[i][1]={x,1}; a[i][2]={y,2}; a[i][3]={z,3};
	}
	s[1]={0,1}; s[2]={0,2}; s[3]={0,3};
	int ans=0;//?
	for(int i=1;i<=n;++i){
		sort(a[i]+1,a[i]+3+1,cmp);
		s[a[i][1].id].w++;
		c[a[i][1].id][i]=a[i][1].w-a[i][2].w; c[a[i][2].id][i]=c[a[i][3].id][i]=inf;
		ans+=a[i][1].w;
	}
	
	sort(s+1,s+3+1,cmp);
	sort(c[s[1].id]+1,c[s[1].id]+n+1);
	
	int tot=0;
	while(s[1].w>n/2){
		ans-=c[s[1].id][++tot]; s[1].w--;
	}
	
	cout<<ans<<"\n"; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	
	return 0;
} 
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
/*
rp++
love pinkrabbit forever 

*/ 
