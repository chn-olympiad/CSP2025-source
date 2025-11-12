#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int n,m;
int a[maxn],mp[maxn][maxn];
pair<int,int> res[maxn];
int sum=0;
int y=1;
bool cmp(int i,int j){
	return i>j;
}
int t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(sum<=n*m){
		for(int i=1;i<=n;i++) mp[i][y]=a[++sum],res[a[sum]]=make_pair(i,y);
		y++;
		for(int i=n;i>=1;i--) mp[i][y]=a[++sum],res[a[sum]]=make_pair(i,y);
		y++;
	}
	cout<<res[t].second<<' '<<res[t].first<<"\n";
	return 0;
}//9.05
