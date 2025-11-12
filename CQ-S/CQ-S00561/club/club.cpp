#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
int n;
int a[N][4];
int num[4];
void work(){
	priority_queue<int>b[4];
	scanf("%lld",&n);
	int ans=0;
	int x,y,z;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x>=y && x>=z){
			ans+=x;
			num[1]++;
			b[1].push(max(y,z)-x);
		}
		else if(y>=x && y>=z){
			ans+=y;
			num[2]++;
			b[2].push(max(x,z)-y);
		}
		else if(z>=y && z>=x){
			ans+=z;
			num[3]++;
			b[3].push(max(x,y)-z);
		}
		
	}
	for(int k=1;k<=3;k++){
		int g=b[k].size()-n/2;
		while(g>0){
			ans+=b[k].top();
			b[k].pop();
			g--;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		work();
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
