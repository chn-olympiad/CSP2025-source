#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,w;
	bool operator < (const node &a)const{return w>a.w;}
}e[10001];
int fa[10010];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y){
	int aa=find(x),bb=find(y);
	fa[bb]=aa;
}
vector<node>g[10001];
int n,m,k,x,y,w;
int f[20][10001];
int c[20];
priority_queue<node>h;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		int sum=0,cnt=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
			h.push(e[i]);
		}
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			node a=h.top();
			h.pop();
			if(find(a.x)!=find(a.y)){
				unionn(a.x,a.y);
				sum+=a.w;
				cnt++;
			}
			if(cnt==n-1)break;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
		}
	}
	int sum1=0x7fffffff;
	for(int l=0;l<(1<<k);l++){
		int sum=0,at[6]={0},j=l,kk=0;
		while(j){
			kk++;
			if(j&1){
				at[kk]=1;
				sum+=c[kk];
			}
			j>>=1;
		}
		for(int i=1;i<=m;i++){
			int minp=e[i].w;
			for(int j=1;j<=5;j++){
				if(at[j])minp=min(minp,f[j][e[i].x]+f[j][e[i].y]);
			}
			h.push((node){e[i].x,e[i].y,minp});
		}
		for(int i=1;i<=n;i++)fa[i]=i;
//		for(int i=1;i<=5;i++){
//			if(at[i]==1){
//				for(int j=1;j<=n;j++)h.push(node(n+i,j,f[i][j]));
//			}
//		}
//		for(int i=)
		int cnt=0;
		for(int i=1;i<=m;i++){
			node a=h.top();
			h.pop();
			if(find(a.x)!=find(a.y)){
				unionn(a.x,a.y);
//				minp=a.w;
//				for(int j=1;j<=5;j++){
//					if(at[j])minp=min(minp,f[j][a.x]+f[j][a.y]);
//				}
				sum+=a.w;
				cnt++;
			}
			if(cnt==n-1)break;
		}
		cout<<sum<<endl;
		sum1=min(sum1,sum);
	}
	cout<<sum1<<endl;
}
/*只不过对那个没问题的话，你我已经不在迷茫
所以啊 ~~~
别多想 妄想感伤代偿联盟
抱着爱和理想高唱着我们
那无处可去的愚者的Melody
再跳转 转生 和瞬间动移
轮回千次最后却无奈放弃
伴随着那无尽的爱舞翩翩起
那 一般 爱情 对象 年龄
恨着爱去维护的那约定
一步步顺着轨迹慢慢变了心 
糟透了 这人际润滑剂
一来 二去 伤地不留 一丝痕迹
混合便成了爱情的philosophy
......
......
I AFOed 
还记得我敲出“Hello World”的那一天吗？
还记得我第一次考模拟考的那一天吗？
在这几年里,我们逃了很多跑操，听了很多术曲，还收获了很多美好的回忆;
我的歌声,如今也该断绝了呢。 
OI,我们应该也缘尽了吧。
...... 
极夜与永昼
别离与欢聚
脉搏与呼吸
找寻着意义 
......
不知道为什么，又哼起那"不为人知"的歌了。 
goodbye OI.
P.S.这是我三天以来的第七场考试，我已老实，求放假。 
又P.S.看到的都去听《世末歌者》！！！ 
*/ 
