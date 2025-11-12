#include<bits/stdc++.h>
#define N 100005
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int t,n,a[N][6],cnt[4];
struct node{
	int id1,mx,id2,cmx;
}b[N];
struct too{
	int id,val;
}c[4];
bool cmp(too P,too Q){
	return P.val>Q.val;
}
int main(){
//	freopen("club3.in","r",stdin);
//	freopen("club3.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		priority_queue< int,vector<int>,greater<int> >q[4];
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				c[j].val=a[i][j];
				c[j].id=j;
			}
			sort(c+1,c+4,cmp);
			int dt=c[1].val-c[2].val;
			q[c[1].id].push(dt);
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			int pos=0,max_=0;
			for(int j=1;j<=3;j++){
				if(max_<a[i][j]){
					max_=a[i][j];
					pos=j;
				}
			}
			ans+=max_;
			cnt[pos]++;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>=n/2){
				int Dt=cnt[i]-n/2;
				while(Dt--){
					ans-=q[i].top();
					q[i].pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
}

