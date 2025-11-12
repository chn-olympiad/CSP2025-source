#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum,ans;
struct h{
	long long x,y,z;
}o[1000005];
long long fa[10005];
bool cmp(h s1,h s2){
	return s1.z<s2.z;
}
long long gfa(long long i){
	if(i==fa[i]){
		return i;
	}else{
		return fa[i]=gfa(fa[i]);
	}
}
void fo(long long i,long long j){
	i=gfa(i);
	j=gfa(j);
	fa[i]=j;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
	for(long long i=1;i<=m;i++){
		cin>>o[i].x>>o[i].y>>o[i].z;
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			long long tp;
			cin>>tp;
		}
	}
	sort(o+1,o+m+1,cmp);
	for(long long i=1;i<=m;i++){
		if(gfa(o[i].x)!=gfa(o[i].y)){
			fo(o[i].x,o[i].y);
			sum+=o[i].z;
			ans++;
			if(ans==n-1){
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
100 1 8 2 4
100 1 8 2 4
*/
