#include<bits/stdc++.h>
using namespace std;
int t,n,b[100010],cnt[5],ans[5];
struct node{
	int x,y,z,id,c;
}a[100010];
bool cmp(node o,node w){
	if(o.c==w.c)return o.id<w.id;
	return o.c>w.c;
}
int read(){
	int x=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
		if(ch=='-')t=-1;
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		memset(ans,0,sizeof ans);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(cnt,0,sizeof cnt);
		int n=read();
		for(int i=1;i<=n;i++){
			int ma=-1,cma=-1;
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			if(a[i].x>ma){
				ma=a[i].x;
				b[i]=1;
			}
			if(a[i].y>ma){
				ma=a[i].y;
				b[i]=2;
			}
			if(a[i].z>ma){
				ma=a[i].z;
				b[i]=3;
			}
			if(b[i]!=1&&a[i].x>cma)cma=a[i].x;
			if(b[i]!=2&&a[i].y>cma)cma=a[i].y;
			if(b[i]!=3&&a[i].z>cma)cma=a[i].z;
			cnt[b[i]]++;
			ans[b[i]]+=ma;
			a[i].id=i;
			a[i].c=cma-ma;
		}
		int sum=ans[1]+ans[2]+ans[3];
		for(int i=1;i<=3;i++){
			while(cnt[i]>n/2){
				sort(a+1,a+n+1,cmp);
				for(int j=1;j<=n&&cnt[i]>n/2;j++){
					if(b[a[j].id]==i){
						cnt[i]--;
						sum+=a[j].c;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

/*3
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
