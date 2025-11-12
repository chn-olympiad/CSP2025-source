#include <bits/stdc++.h>
using namespace std;
namespace lch{
const int N=1e5+10;
int n,a[N][3];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j:{0,1,2}) scanf("%d",&a[i][j]);
	}
	// int c[3]={0,0,0};
	int sum=0;
	vector<int> v[3];
	for(int i=1;i<=n;i++){
		int j=max_element(a[i],a[i]+3)-a[i];
		// c[j]++;
		sum+=a[i][j];
		int oth=-1;
		for(int k:{0,1,2}) if(k!=j&&(oth==-1||a[i][k]>a[i][oth])) oth=k;
//		printf("%d %d %d\n",i,j,oth);
		v[j].push_back(a[i][oth]-a[i][j]);
	}
	int mxsiz=-1,p=-1;
	for(int c:{0,1,2}){
		if((int)v[c].size()>mxsiz){
			p=c; mxsiz=v[c].size();
		}
	}
//	printf("%d %d\n",mxsiz,p);
	assert(p!=-1);
	if(mxsiz<=n/2){
		printf("%d\n",sum);
		return;
	}
	sort(v[p].begin(),v[p].end()); reverse(v[p].begin(),v[p].end());
	for(int i=0;i<mxsiz-n/2;i++) sum+=v[p][i];
	printf("%d\n",sum);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
	return 0;
}
}
int main(){
#ifndef LCH
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	return lch::main();
}

