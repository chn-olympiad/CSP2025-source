#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define N 100005
using namespace std;
int t,n,a[N][5],ans,d[N];
bool v1[N],v2[N],v3[N];
struct code {
	int val,id;
} t1[N],t2[N],t3[N];
bool cmp(code x,code y) {
	return x.val<y.val;
}
void dfs(int i,int s1,int s2,int s3,int tmp){
	if(i>n){
		ans=max(ans,tmp);
		return;
	}
	if(s1<n/2){
		dfs(i+1,s1+1,s2,s3,tmp+a[i][1]);
	}
	if(s2<n/2){
		dfs(i+1,s1,s2+1,s3,tmp+a[i][2]);
	}
	if(s3<n/2){
		dfs(i+1,s1,s2,s3+1,tmp+a[i][3]);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		int cnt=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%d",&a[i][j]);
				if(j==2||j==3){
					if(a[i][j]){
						++cnt;
					}
				}
			}
		}
		if(!cnt){
			for(int i=1;i<=n;i++){
				d[i]=a[i][1];
			}
			sort(d+1,d+n+1);
			ans=0;
			for(int i=n;i>=n/2+1;i--){
				ans+=d[i];
			}
			printf("%d\n",ans);
		}else if(n<=30) {
			ans=0;
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		} else {
			for(int i=1; i<=n; i++) {
				t1[i].val=a[i][1];
				t2[i].val=a[i][2];
				t3[i].val=a[i][3];
				t1[i].id=t2[i].id=t3[i].id=i;
			}
			sort(t1+1,t1+n+1,cmp);
			sort(t2+1,t2+n+1,cmp);
			sort(t3+1,t3+n+1,cmp);
			int s1=0,s2=0,s3=0;
			memset(v1,false,sizeof(v1));
			memset(v2,false,sizeof(v2));
			memset(v3,false,sizeof(v3));
			for(int i=n; i>=n/2+1; i--) {
				s1+=t1[i].val;
				v1[t1[i].id]=true;
				s2+=t2[i].val;
				v2[t2[i].id]=true;
				s3+=t3[i].val;
				v3[t3[i].id]=true;
			}
			for(int i=n,j=n,cnt=1; i>=1&&j>=1&&cnt<=n/2;) {
				while(v1[t2[i].id]&&i>=1) {
					--i;
				}
				while(v1[t3[j].id]&&j>=1) {
					--j;
				}
				if(t2[i].val>t3[j].val) {
					s1+=t2[i].val;
					v1[t2[i].id]=true;
					--i;
					++cnt;
				} else {
					s1+=t3[j].val;
					v1[t3[j].id]=true;
					--j;
					++cnt;
				}
			}
			for(int i=n,j=n,cnt=1; i>=1&&j>=1&&cnt<=n/2;) {
				while(v2[t1[i].id]&&i>=1) {
					--i;
				}
				while(v2[t3[j].id]&&j>=1) {
					--j;
				}
				if(t1[i].val>t3[j].val) {
					s2+=t1[i].val;
					v2[t1[i].id]=true;
					--i;
					++cnt;
				} else {
					s2+=t3[j].val;
					v2[t3[j].id]=true;
					--j;
					++cnt;
				}
			}
			for(int i=n,j=n,cnt=1; i>=1&&j>=1&&cnt<=n/2;) {
				while(v3[t1[i].id]&&i>=1) {
					--i;
				}
				while(v3[t2[j].id]&&j>=1) {
					--j;
				}
				if(t1[i].val>t2[j].val) {
					s3+=t1[i].val;
					v3[t1[i].id]=true;
					--i;
					++cnt;
				} else {
					s3+=t2[j].val;
					v3[t2[j].id]=true;
					--j;
					++cnt;
				}
			}
			printf("%d\n",max(s1,max(s2,s3)));
		}

	}
	return 0;
}
