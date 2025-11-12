#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+10,M=5e6+10;
int n,q,minn,maxn;
ll ans=0;
char st[M];
struct node{
	int len;
	vector<int> a[2],nxt[2];
}s[N],now;
int vis[2][M];
void solve(int id){
	int len=s[id].len;
	for(int h=0;h<=1;h++){
		s[id].nxt[h].reserve(len+1);
		s[id].nxt[h].push_back(0);
		for(int i=2,j=0;i<=len;i++){
			while(j>0&&j+1<=len&&s[id].a[h][j+1]!=s[id].a[h][i]) j=s[id].nxt[h][j];
			if(j+1<=len&&s[id].a[h][j+1]==s[id].a[h][i]) j++;
			s[id].nxt[h].push_back(j);
//			cout<<id<<" "<<h<<" "<<i<<" "<<j<<" "<<s[id].a[h][i]<<endl;
		}
	}
	return ;
}
void calc(int id){
//	cout<<minn<<" "<<maxn<<endl;
	int len=s[id].len;
	for(int h=0;h<=1;h++){
		for(int i=1,j=0;i<=now.len;i++){
			while(j>0&&j+1<=len&&s[id].a[h][j+1]!=now.a[h][i]) j=s[id].nxt[h][j];
			if(j+1<=len&&s[id].a[h][j+1]==now.a[h][i]) j++;
			if(j==len) vis[h][i]=1,j=s[id].nxt[h][j];
			else vis[h][i]=0;
//			if(id==3) cout<<id<<" "<<h<<" "<<i<<" "<<j<<" "<<now.a[h][j]<<" "<<s[id].a[h][i]<<endl;
			if(i-len+1>minn) break;
		}
	}
	for(int i=1;i<=now.len;i++){
		if(vis[0][i]&&vis[1][i]&&(i-len+1<=minn)&&(i>=maxn)) ans++;
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",st+1);
		s[i].len=strlen(st+1),s[i].a[0].reserve(s[i].len+1),s[i].a[0].push_back(0);
		for(int j=1;j<=s[i].len;j++) s[i].a[0].push_back((int)(st[j]-'a'));
		scanf("%s",st+1);
		s[i].a[1].reserve(s[i].len+1),s[i].a[1].push_back(0);
		for(int j=1;j<=s[i].len;j++) s[i].a[1].push_back((int)(st[j]-'a'));
		solve(i);
	}
	for(int i=1;i<=q;i++){
		now.a[0].clear(),now.a[1].clear();
		scanf("%s",st+1);
		now.len=strlen(st+1),now.a[0].reserve(now.len+1),now.a[0].push_back(0);
		for(int j=1;j<=now.len;j++) now.a[0].push_back((int)(st[j]-'a'));
		scanf("%s",st+1);
		int len1=strlen(st+1);
		if(len1!=now.len){
			printf("0\n");
			continue;
		}
		now.a[1].reserve(now.len+1),now.a[1].push_back(0);
		minn=1e9,maxn=0;
		for(int j=1;j<=now.len;j++){
			now.a[1].push_back((int)(st[j]-'a'));
			if(now.a[0][j]!=now.a[1][j]) minn=min(minn,j),maxn=j;
		}
		ans=0;
		for(int i=1;i<=n;i++) calc(i);
		printf("%lld\n",ans);
	}
	return 0;
}
