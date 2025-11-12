#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int n,a[N][4];
vector<int>v[4];
bool cmp1(int x,int y){
	return min(a[x][1]-a[x][2],a[x][1]-a[x][3])>min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
bool cmp2(int x,int y){
	return min(a[x][2]-a[x][1],a[x][2]-a[x][3])>min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
}
bool cmp3(int x,int y){
	return min(a[x][3]-a[x][1],a[x][3]-a[x][2])>min(a[y][3]-a[y][1],a[y][3]-a[y][2]);
}
void solve(){
	v[1].clear();
	v[2].clear();
	v[3].clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])v[1].push_back(i),ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])v[2].push_back(i),ans+=a[i][2];
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])v[3].push_back(i),ans+=a[i][3];
	}
	if((int)v[1].size()>n/2){
		stable_sort(v[1].begin(),v[1].end(),cmp1);
		for(int i=n/2;i<(int)v[1].size();i++){
			int j=v[1][i];
			ans-=min(a[j][1]-a[j][2],a[j][1]-a[j][3]);
		}
	}
	else if((int)v[2].size()>n/2){
		stable_sort(v[2].begin(),v[2].end(),cmp2);
		for(int i=n/2;i<(int)v[2].size();i++){
			int j=v[2][i];
			ans-=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);
		}
	}
	else if((int)v[3].size()>n/2){
		stable_sort(v[3].begin(),v[3].end(),cmp3);
		for(int i=n/2;i<(int)v[3].size();i++){
			int j=v[3][i];
			ans-=min(a[j][3]-a[j][1],a[j][3]-a[j][2]);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while(_--)solve();
	return 0;
}
