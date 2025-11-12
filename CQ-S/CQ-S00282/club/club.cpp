#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=1e5;
int T,n,num[3],flag[N+5];
long long a[N+5][3];
struct node{
	long long val;
	int id,to;
	bool operator<(const node&other)const{
		return val<other.val;
	}
};
priority_queue<node>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		long long ans=0;
		scanf("%d",&n);
		fre(i,1,n,1)fre(j,0,2,1)scanf("%lld",&a[i][j]);
		fre(i,0,2,1)num[i]=0;
		fre(i,1,n,1)fre(op,0,2,1)if(a[i][op]>=a[i][(op+1)%3]&&a[i][op]>=a[i][(op+2)%3]){flag[i]=op,num[op]++,ans+=a[i][op];break;}
		fre(op,0,2,1)if(num[op]>n/2){
			while(!q.empty())q.pop();
			fre(i,1,n,1)if(flag[i]==op){
				if(a[i][(op+1)%3]>=a[i][(op+2)%3])q.push({a[i][(op+1)%3]-a[i][op],i,(op+1)%3});
				else q.push({a[i][(op+2)%3]-a[i][op],i,(op+2)%3});
			}
			while(num[op]>n/2){
				int id=q.top().id,to=q.top().to;q.pop();
				num[op]--,num[to]++,flag[id]=to;
				ans+=a[id][to]-a[id][op];
			}
			while(!q.empty())q.pop();
			if(num[(op+1)%3]>n/2){
				fre(i,1,n,1)if(flag[i]==(op+1)%3)q.push({a[i][(op+2)%3]-a[i][(op+1)%3],i,(op+2)%3});
				while(num[(op+1)%3]>n/2){
					int id=q.top().id,to=q.top().to;q.pop();
					num[(op+1)%3]--,num[to]++,flag[id]=to;
					ans+=a[id][to]-a[id][num[(op+1)%3]];
				}
			}
			else if(num[(op+2)%3]>n/2){
				fre(i,1,n,1)if(flag[i]==(op+2)%3)q.push({a[i][(op+1)%3]-a[i][(op+2)%3],i,(op+1)%3});
				while(num[(op+2)%3]>n/2){
					int id=q.top().id,to=q.top().to;q.pop();
					num[(op+2)%3]--,num[to]++,flag[id]=to;
					ans+=a[id][to]-a[id][num[(op+2)%3]];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}