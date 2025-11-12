#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Maxn=1e5+10;

struct Node {
	int id,di,val[5];
};

int T,n,vis[Maxn],cnt[5],sum,cun[5][Maxn],a[Maxn][5];

bool cmp(Node x,Node y) {
	if(x.val[x.di]==y.val[y.di]) {
		int tag=0,Val=0;
		for(int i=1;i<=3;i++) {
			if(x.di==i)continue;
			if(x.val[i]>Val) {
				Val=x.val[i];
				tag=x.id;
			}
		}
		for(int i=1;i<=3;i++) {
			if(y.di==i)continue;
			if(y.val[i]>Val) {
				Val=y.val[i];
				tag=y.id;
			}
		}
		if(tag==x.id)return false;//y xianfang
		else return true;//x xianfang
	} else
		return x.val[x.di]>y.val[y.di];
}

int solve(int level,int x,int y,int z) {
	if(level==n+1)return 0;
	int sum=0;
//	if(dp[level][x][y][z]!=-1)return dp[level][x][y][z];
	if(x<n/2) {
		sum=max(sum,solve(level+1,x+1,y,z)+a[level][1]);
	}
	if(y<n/2) {
		sum=max(sum,solve(level+1,x,y+1,z)+a[level][2]);
	}
	if(z<n/2) {
		sum=max(sum,solve(level+1,x,y,z+1)+a[level][3]);
	}
	return sum;
}

vector<Node>L;

int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--) {
		
		Node tmp;
		L.clear();
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		sum=0;
		
		scanf("%d",&n);
		
		if(n<=15) {
			for(int i=1;i<=n;i++)
				scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			printf("%d\n",solve(1,0,0,0));
			continue;
		}
		
		for(int i=1;i<=n;i++) {
			scanf("%d %d %d",&tmp.val[1],&tmp.val[2],&tmp.val[3]);
		
			tmp.id=i;
			tmp.di=1;
			L.push_back(tmp);
			
			tmp.id=i;
			tmp.di=2;
			L.push_back(tmp);
			
			tmp.id=i;
			tmp.di=3;
			L.push_back(tmp);
			
			
		}
		sort(begin(L),end(L),cmp);
		
		int len=L.size();
		
//		for(int i=0;i<len;i++) {
//			printf("%d %d %d\n",L[i].id,L[i].di,L[i].val[L[i].di]);
//		}
		
		for(int i=0;i<len;i++) {
			
			Node tag=L[i];
			
			if(vis[tag.id])continue;
			if(cnt[tag.di]>=n/2) {
				
//				int last_id=cun[tag.di][cnt[tag.di]];
//				
//				if(tag.di==1) {
//					if(cnt[2]<n/2) {
//						if(sum-=)
//					}
//					if(cnt[3]<n/2) {
//						
//					}
//				}
				continue;
			}
			
			sum+=tag.val[tag.di];
			vis[tag.id]=1;
			cnt[tag.di]++;
//			cun[tag.di][cnt[tag.di]]=tag.id;
		}
		printf("%d\n",sum);
	}
	return 0;
}
