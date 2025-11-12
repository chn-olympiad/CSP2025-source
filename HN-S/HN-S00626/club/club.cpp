#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0){
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
int n,cnt[4],sum;
struct node{
	int a[4],del,maxn,maxid;
	bool operator <(const node &x)const{
		return del<x.del;
	}
};
node q[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--){
		memset(cnt,0,sizeof(cnt));
		sum=0;
		n=read();
		for(int i=1;i<=n;i++){
			q[i].a[1]=read();
			q[i].a[2]=read();
			q[i].a[3]=read();
			q[i].maxn=max(q[i].a[1],max(q[i].a[2],q[i].a[3]));
			int minn=min(q[i].a[1],min(q[i].a[2],q[i].a[3]));
			q[i].del=q[i].maxn-(q[i].a[1]+q[i].a[2]+q[i].a[3]-q[i].maxn-minn);
			if(q[i].maxn==q[i].a[1]){
				q[i].maxid=1;
			}
			else if(q[i].maxn==q[i].a[2]){
				q[i].maxid=2;
			}
			else{
				q[i].maxid=3;
			}
			if(q[i].del==0){
				q[i].maxid=0;
			}
		}
		sort(q+1,q+n+1);
		for(int i=1;i<=n;i++){
			sum+=q[i].maxn;
			cnt[q[i].maxid]++;
		}
		int id=0;
		if(cnt[1]>n/2){
			id=1;
		}
		else if(cnt[2]>n/2){
			id=2;
		}
		else if(cnt[3]>n/2){
			id=3;
		}
		if(!id){
			write(sum);
			putchar('\n');
			continue;
		}
		for(int i=1;i<=n;i++){
			if(q[i].maxid==id){
				sum-=q[i].del;
				cnt[id]--;
				if(cnt[id]<=n/2){
					break;
				}
			}
		}
		write(sum);
		putchar('\n');
	}
	return 0;
}
