#include<bits/stdc++.h>//onno ijust doless than1T
#define int long long//how can that be?
using namespace std;//butas before i'll love u forever Ljn&Six_Flower ty!!
int n;
bool k1=1,k2=1;
int now[100010];
struct node{
	int x,y,z;
}x[100010];
int ans,sam[4];
struct lsx{
	int p,to,w;
}idk1[200020],idk2[200020],idk3[200020];
int id1,id2,id3;
bool cmd(lsx l,lsx r){
	return l.w<r.w;
}
bool cmd1(node l,node r){
	return l.x>l.y;
}
int noww;
void dfs(int p){
//	cout<<p<<'\n';
	if(p>n){
		ans=max(ans,noww);
		return ;
	}
	if(sam[1]+1<=n/2){
		noww+=x[p].x;
		sam[1]++;
		dfs(p+1);
		noww-=x[p].x;
		sam[1]--;
	}
	if(sam[2]+1<=n/2){
		noww+=x[p].y;
		sam[2]++;
		dfs(p+1);
		noww-=x[p].y;
		sam[2]--;
	}
	if(sam[3]+1<=n/2){
		noww+=x[p].z;
		sam[3]++;
		dfs(p+1);
		noww-=x[p].z;
		sam[3]--;
	}
	return ;
}
signed main(){
//	freopen("club3.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,sam[1]=sam[2]=sam[3]=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].x>>x[i].y>>x[i].z;
			int maxx=max(x[i].x,max(x[i].y,x[i].z));
			if(maxx==x[i].x) now[i]=1,sam[1]++,idk1[++id1].p=i,idk1[id1].to=2,idk1[id1].w=x[i].x-x[i].y, idk1[++id1].p=i,idk1[id1].to=3,idk1[id1].w=x[i].x-x[i].z;
			else if(maxx==x[i].y) now[i]=2,sam[2]++,idk2[++id2].p=i,idk2[id2].to=1,idk2[id2].w=x[i].y-x[i].x, idk2[++id2].p=i,idk2[id2].to=3,idk2[id2].w=x[i].y-x[i].z;
			else now[i]=3,sam[3]++,idk3[++id3].p=i,idk3[id3].to=1,idk3[id3].w=x[i].z-x[i].x, idk3[++id3].p=i,idk3[id3].to=2,idk3[id3].w=x[i].z-x[i].y;
			ans+=maxx;
			if(x[i].y!=0||x[i].z!=0) k1=0;
		}
		if(k1){
			ans=0;
			sort(x+1,x+1+n,cmd1);
			for(int i=1;i<=n/2;i++){
//				cout<<x[i].x<<' ';
				ans+=x[i].x;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n<=10){
			ans=0;
			sam[1]=sam[2]=sam[3]=0;
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
		int k=1;
		while(sam[k]<=n/2&&k<=3) k++;
		if(k>3){
			cout<<ans<<'\n';
			continue;
		}
		if(k==1){
			sort(idk1+1,idk1+1+id1,cmd);
			int t=1;
			while(sam[k]>n/2){
				while(now[idk1[t].p]!=1||sam[idk1[t].to]+1>n/2) t++;
				ans-=idk1[t].w;
				sam[idk1[t].to]++;
				sam[k]--;
			}
		}
		if(k==2){
			sort(idk2+1,idk2+1+id2,cmd);
			int t=1;
			while(sam[k]>n/2){
				while(now[idk2[t].p]!=2||sam[idk2[t].to]+1>n/2) t++/*,cout<<(now[idk2[t].p]!=1)<<(sam[idk2[t].to]+1>n/2)<<'\n'*/;
				ans-=idk2[t].w;
				sam[idk2[t].to]++;
				sam[k]--;
			}
		}
		if(k==3){
			sort(idk3+1,idk3+1+id3,cmd);
			int t=1;
			while(sam[k]>n/2){
				while(now[idk3[t].p]!=2||sam[idk3[t].to]+1>n/2) t++;
				ans-=idk3[t].w;
				sam[idk3[t].to]++;
				sam[k]--;
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
/*
1
8
1 0 0 2 0 0 3 0 0 4 0 0 5 0 0 6 0 0 7 0 0 8 0 0
*/
