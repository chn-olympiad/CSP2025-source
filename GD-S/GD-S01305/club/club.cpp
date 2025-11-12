#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct member{
	int a1,a2,a3;
	int diff,maxidx,maxn;
}M[5][100005];
bool comp(member a, member b){
	if(a.maxidx != b.maxidx){
		return a.maxidx < b.maxidx;
	}
	else{
		return a.diff < b.diff;
	}
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T; cin>>T;
	for(int t = 0;t<T;t++){
		int n; cin>>n;
		int cnt[4] = {};
		for(int i = 0;i<n;i++){
			scanf("%d %d %d",&M[t][i].a1,&M[t][i].a2,&M[t][i].a3);
			int maxa = max(M[t][i].a1,max(M[t][i].a2,M[t][i].a3));
			if(maxa == M[t][i].a1){
				M[t][i].maxidx = 1; M[t][i].diff = M[t][i].a1 - max(M[t][i].a2,M[t][i].a3);
				cnt[1]++;
			}
			else if(maxa == M[t][i].a2){
				M[t][i].maxidx = 2; M[t][i].diff = M[t][i].a2 - max(M[t][i].a1,M[t][i].a3);
				cnt[2]++;
			}
			else if(maxa == M[t][i].a3){
				M[t][i].maxidx = 3; M[t][i].diff = M[t][i].a3 - max(M[t][i].a2,M[t][i].a1);
				cnt[3]++;
			}
			M[t][i].maxn = maxa;
		}
		sort(M[t],M[t]+n,comp);
		int ans = 0;
		for(int i = 0;i<n;i++){
			if(cnt[M[t][i].maxidx] <= n/2){
				ans += M[t][i].maxn;
			}
			else{
				ans += M[t][i].maxn - M[t][i].diff;
				cnt[M[t][i].maxidx]--;
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
