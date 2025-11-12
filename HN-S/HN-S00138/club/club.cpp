#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int n,T,maxx,cnt,idx,k,b,c,ans,minn,ans2;
bool flag;
bool vis[maxn];
int tot[maxn],p[maxn][5];
int cur[maxn],A[maxn];

struct tmp{
	int p;
	int val;
};

struct node{
	tmp t[4];
};

node a[maxn];

int nxt(int x){
	if(x==3){
		return 1;
	}
	return x+1;
}

int lst(int x){
	if(x==1){
		return 3;
	}
	return x-1;
}

int val(node x){
	int minn=1e9;
	for(int i=1;i<=3;i++){
		minn=min(minn,x.t[lst(i)].val+x.t[nxt(i)].val);
	}
	return minn;
}

bool cmp1(node x,node y){
	if(val(x)==val(y)){
		return max({x.t[1].val,x.t[2].val,x.t[3].val})<max({y.t[1].val,y.t[2].val,y.t[3].val});
	}
	return val(x)<val(y);
}

void work(){
	int lp=0;
	for(int i=1;i<=n;i++){
		lp+=p[i][cur[i]];
	}
	maxx=max(maxx,lp);
	return;
}

void dfs(int step){
	if(step>n){
		work();
		return;
	}
	for(int i=1;i<=3;i++){
		if(tot[i]+1>n/2){
			continue;
		}
		tot[i]++;
		cur[step]=i;
		dfs(step+1);
		tot[i]--;
	}
	return;
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=20){
			maxx=0;
			for(int i=1;i<=n;i++){
				cin>>p[i][1]>>p[i][2]>>p[i][3];
			}
			dfs(1);
			cout<<maxx<<'\n';
			continue;
		}
		tot[1]=tot[2]=tot[3]=ans=ans2=0;
		flag=0;
		for(int i=1;i<=n;i++){
			cin>>k>>b>>c;
			ans+=k+b+c;
			flag=b|c;
			vis[i]=0;
			A[i]=k;
			a[i].t[1]={1,k};
			a[i].t[2]={2,b};
			a[i].t[3]={3,c};
		}
		if(!flag){
			sort(A+1,A+1+n);
			for(int i=n;i>=n/2;i--){
				ans2+=A[i];
			}
			cout<<ans2<<'\n';
			continue;
		}
		sort(a+1,a+1+n,cmp1);
//		for(int i=1;i<=n;i++){
//			cout<<val(a[i])<<'\n';
//		}
		for(int i=1;i<=n;i++){
			minn=1e9;
			for(int j=1;j<=3;j++){
				if(tot[a[i].t[j].p]+1<=n/2){
					if(a[i].t[lst(j)].val+a[i].t[nxt(j)].val<minn){
						minn=a[i].t[lst(j)].val+a[i].t[nxt(j)].val;
						idx=j;
					}
				}
			}
			ans-=minn;
			tot[a[i].t[idx].p]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

1
2
10 9 8
4 0 0



1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/
