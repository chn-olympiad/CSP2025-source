#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#define int long long
using namespace std;

void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
int t,n,a[100010][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		int res=0;
		vector<int> ext[3];
		for(int i=1;i<=n;i++){
			read(a[i][0]);
			read(a[i][1]);
			read(a[i][2]);
			if(a[i][0]>a[i][1] && a[i][0]>a[i][2]){
				ext[0].push_back(max(a[i][1],a[i][2])-a[i][0]);
				res+=a[i][0];
			}
			if(a[i][1]>=a[i][0] && a[i][1]>a[i][2]){
				ext[1].push_back(max(a[i][0],a[i][2])-a[i][1]);
				res+=a[i][1];
			}
			if(a[i][2]>=a[i][0] && a[i][2]>=a[i][1]){
				ext[2].push_back(max(a[i][0],a[i][1])-a[i][2]);
				res+=a[i][2];
			}
		}
		int id=-1;
		for(int i=0;i<3;i++){
			if(ext[i].size()>n/2){
				id=i;
			}
		}
		if(!~id){
			printf("%lld\n",res);
			continue;
		}
		sort(ext[id].begin(),ext[id].end());
		while(ext[id].size()>n/2){
			res+=ext[id].back();
			ext[id].pop_back();
		}
		printf("%lld\n",res);
	}
	return 0;
}
