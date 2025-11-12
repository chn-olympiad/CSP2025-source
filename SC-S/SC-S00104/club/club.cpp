#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
#define VI vector<LL>
using namespace std;
struct person{int pos,val;};
bool cmp(person a,person b){
	return a.val>b.val;}
bool cmp2(vector<person> a,vector<person> b){
	rep(i,1,a.size()){
		rep(j,1,b.size()){
			if(a[i].pos==b[j].pos){
				return a[i].val>b[j].val;}}}}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int club[4];
		memset(club,0,sizeof(club));
		vector<vector<person>> a(n+1,vector<person>(4));
		rep(i,1,n){
			rep(j,1,3){
				a[i][j].pos=j;
				cin>>a[i][j].val;}}
		rep(i,1,n)sort(a[i].begin()+1,a[i].end(),cmp);
		LL ans=0,sum=LLONG_MIN;
		sort(a.begin()+1,a.end(),cmp2);
		int last=1;bool re=true;
		rep(p,1,n){
			rep(i,1,n){
				rep(j,last,3){
					if(last!=1&&re)j=0,re=false;
					if(club[a[i][j].pos]<n/2){
						ans+=a[i][j].val,club[a[i][j].pos]++;break;}}}
			last++;
			memset(club,0,sizeof(club));
			sum=max(sum,ans);
			ans=0;
			re=true;}
		cout<<sum<<"\n";}}