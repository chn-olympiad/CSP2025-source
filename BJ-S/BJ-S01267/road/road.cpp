#include<bits/stdc++.h>
#include<map>
using namespace std;
long long n,m,k,a[10005],b[10005],cnt;
struct people{
	long long p,w;
};
map<long long,people>mp[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int ai,bi,wi;
		cin>>ai>>bi>>wi;
		mp[ai][0].p++;
		mp[ai][mp[ai][0].p].w=wi;
		mp[ai][mp[ai][0].p].p=bi;
		mp[bi][0].p++;
		mp[bi][mp[bi][0].p].w=wi;
		mp[bi][mp[bi][0].p].p=ai;
	}
	for(int i=2;i<=n;i++){
		long long minn=1e18,minid=i;
		for(int j=1;j<=mp[i][0].p;j++){
			if(mp[i][j].p<=i-1){
				if(mp[i][j].w<a[mp[i][j].p]||a[mp[i][j].p]==0){
					if(a[mp[i][j].p]<minn){
						minn=a[mp[i][j].p];
						minid=mp[i][j].p;
					}
					a[mp[i][j].p]=mp[i][j].w;
				}
			}
		}
		for(int j=1;j<=mp[i][0].p;j++){
			if(mp[i][j].p<=i-1){
				if(mp[i][j].w<minn){
					minn=mp[i][j].w;
					minid=i;
				}
			}
		}
		if(minid==i)a[i]=minn;
		else{
			a[i]=a[minid];
			a[minid]=minn;
		}
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[n];
	}
	cout<<cnt;
	return 0;
}