//考虑建出两个 AC 自动机然后 dp？
//S 匹配的一个后缀和 T 匹配的一个后缀 id 相同
#include<bits/stdc++.h>
using namespace std;
//bool st;
const int N=200010,M=2500010;
struct ACAM{
	int cnt,dep[M],lst[M],ch[M][26];
	vector<int> bot[M];
	ACAM(){cnt=1,dep[1]=0;}
	queue<int> q;
	void insert(char *c,int id){
		int i,j;
		for(i=1,j=1;c[i];i++){
			int o=c[i]-'a';
			if(!ch[j][o]) ch[j][o]=++cnt,dep[cnt]=dep[j]+1;
			j=ch[j][o];
		}
		bot[j].push_back(id);
	}
	void bfs(){
		for(int i=0;i<26;i++) ch[0][i]=1;
		lst[1]=0;
		q.push(1);
		while(!q.empty()){
			int x=q.front();
			q.pop();
//			printf("%d->%d\n",x,lst[x]);
			for(int k=0;k<26;k++){
				if(!ch[x][k]) ch[x][k]=ch[lst[x]][k];
				else{
					lst[ch[x][k]]=ch[lst[x]][k];
					q.push(ch[x][k]);
				}
			}
		}
	}
}d[2];
int n,q;
char c[M],s[M];
unordered_set<int> t;
//bool ed;
int main(){
//	cout<<((&st)-(&ed))/1024/1024<<endl;
//	system("fc replace.out replace3.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",c+1,s+1);
		d[0].insert(c,i),d[1].insert(s,i);
	}
	d[0].bfs(),d[1].bfs();
	for(int i=1;i<=q;i++){
		int lc=0,ls=0;
		scanf("%s%s",c+1,s+1);
		for(lc=1;c[lc];lc++) ;
		for(ls=1;s[ls];ls++) ;
		if(lc!=ls){
			printf("0\n");
			continue;
		}
		int x=1,y=1,ans=0,L=lc,R=0;
		for(int j=lc-1;j;j--) if(c[j]!=s[j]) L=j;
		for(int j=1;j<lc;j++) if(c[j]!=s[j]) R=j;
		for(int j=1;j<lc;j++){
			x=d[0].ch[x][c[j]-'a'];
			y=d[1].ch[y][s[j]-'a'];
//			printf("%d %d\n",x,y);
			int nx=x,ny=y;
			t.clear();
			while(nx){
				for(auto k:d[0].bot[nx]) t.insert(k);
				nx=d[0].lst[nx];
			}
			while(ny){
				if(j-d[1].dep[ny]+1<=L&&R<=j){
					for(auto k:d[1].bot[ny]){
						if(t.find(k)!=t.end()) ans++;
					}
				}
				ny=d[1].lst[ny];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
