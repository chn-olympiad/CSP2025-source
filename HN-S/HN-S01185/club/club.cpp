#include<bits/stdc++.h>
using namespace std;
int n,T,maxn=0;
const int N=1e5+7;
struct node{
	long long a;
	long long  b;
	long long c;
	long long all;
}s[N];
int vis[N][4],ll[4];
long long ans;
/*struct xp{
	long long num;
	int an;
	int bn;
	int cn;
}*/
void dfs(long long now,int x,int y,int z,long long now_ans){
	if(now>n){
		ans=max(ans,now_ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			if(x<maxn){
				dfs(now+1,x+1,y,z,now_ans+s[now].a);
			}
		}
		if(i==2){
			if(y<maxn){
				dfs(now+1,x,y+1,z,now_ans+s[now].b);
			}
		}
		if(i==3){
			if(z<maxn){
				dfs(now+1,x,y,z+1,now_ans+s[now].c);
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		maxn=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].all=s[i].a+s[i].b+s[i].c;
		}
//		f[1][1][1]=s[1].a;
//		f[1][1][2]=1;
//		f[1][2][1]=s[1].b;
//		f[1][2][3]=1;
//		f[1][3][1]=s[1].c;
//		f[1][3][4]=1;
//		long long all_ans=0;
//		for(int i=2;i<=n;i++){
//			if(f[i-1][1][2]<maxn){
//				if(f[i][1][1]<f[i-1][1][1]+s[i].a){
//					f[i][1][1]=max(f[i][1][1],f[i-1][1][1]+s[i].a);
//					f[i][1][2]=f[i-1][1][2]+1;
//				}
//			}
//			if(f[i-1][1][3]<maxn){
//				f[i][1][1]=max(f[i][1][1],f[i-1][1][1]+s[i].a);
//				f[i][1][2]=f[i-1][1][2]+1;
//			}
//		}
		if((long long)pow(3,n)<=(long long)1e8)dfs(0,0,0,0,0);
		else{
//			sort(s+1,s+n+1,cmp);
			ans=max(s[1].a,max(s[1].b,s[1].c));
			for(int i=2;i<=n;i++){
				if(ll[1]<=maxn ){
					if(s[i-1].a<s[i-1].b+s[i].a && ll[2]<maxn){
						ans+=s[i-1].b+s[i].a;
						ans-=s[i-1].a;
						ll[2]++;
					}
					if(s[i-1].a<s[i-1].c+s[i].a && ll[3]<=maxn){
						ans+=s[i-1].c+s[i].a;
						ans-=s[i-1].a;
						ll[3]++;
					}
				}
				if(ll[2]<=maxn ){
					if(s[i-1].b<s[i-1].a+s[i].b && ll[1]<maxn){
						ans+=s[i-1].a+s[i].b;
						ans-=s[i-1].b;
						ll[1]++;
					}
					if(s[i-1].b<s[i-1].c+s[i].b && ll[3]<=maxn){
						ans+=s[i-1].c+s[i].b;
						ans-=s[i-1].b;
						ll[3]++;
					}
				}
				if(ll[3]<=maxn ){
					if(s[i-1].c<s[i-1].a+s[i].c && ll[1]<maxn){
						ans+=s[i-1].a+s[i].c;
						ans-=s[i-1].c;
						ll[1]++;
					}
					if(s[i-1].c<s[i-1].b+s[i].c && ll[2]<=maxn){
						ans+=s[i-1].b+s[i].c;
						ans-=s[i-1].c;
						ll[2]++;
					}
				}
			}
		}
		cout<<ans<<'\n';
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
