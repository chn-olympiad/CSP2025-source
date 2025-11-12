#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001][4],t,n;
vector<int>g;
int ans=0;
vector<pair<int,int> >g2;
bool vis[1145141];
void dfs(int dep,int sum,int aa,int bb,int cc){
	if(aa<=n/2&&bb<=n/2&&cc<=n/2){
		ans=max(ans,sum);
	}
	if(dep>n)
	return ;
	if(aa<=n/2){
		dfs(dep+1,sum+a[dep][1],aa+1,bb,cc);
	}
	if(bb<=n/2){
		dfs(dep+1,sum+a[dep][2],aa,bb+1,cc);
	}
	if(cc<=n/2){
		dfs(dep+1,sum+a[dep][3],aa,bb,cc+1);	
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(NULL));
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)
			flag1=false;
			if(a[i][3]!=0)
			flag2=false;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		if(flag1){
			g.clear();
			for(int i=1;i<=n;i++){
				g.push_back(-a[i][1]);
			}
			sort(g.begin(),g.end());
			for(int i=0;i<g.size()/2;i++){
				ans-=g[i];
			}
			cout<<ans<<'\n';
			continue;
		}//A
		else{
			for(int i=1;i<=n;i++){
				ans+=max(max(a[i][i],a[i][2]),a[i][3]);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
//25
/*
非常悲伤啊，感觉这次csps又要炸掉了
本人高一生，从初一开始学oi，结果什么成绩都没打出来
唉，这次的csps也不会，已经做好打完这一场就退队然后卷文化课了(骗你的，卷文化课也卷不过别人) 

T1好像是贪心，又像是神秘dp，可惜我都不会
T2 感觉像是一个变种的最小生成树，但我不会处理，遂打特殊性质！但是我突然发现忘记克鲁斯卡尔怎么写了，直接绷不住了
T3 根本看不懂，什么神秘字符串题
T4 是神秘计数题，可我根本看不懂，遂打暴力，本来想写特殊性质A的，但想了想发现有点难实现就没写了

回想我这三年来的学OI历程，真令人想痛骂我自己
早知道就不看少女乐队了
早知道就不看蛊真人了
早知道就不玩明日方舟了
早知道就不听音乐了
唉，真令人遗憾。 

希望D同学可以考个理想的成绩，然后进入noip继续打下去。
希望L同学可以考个理想的成绩，然后进入noip继续打下去。
希望Z同学可以把交友的方法告诉我，让我也能像他一样。
希望RP发力，四题都交了rand，可不可以多一点分啊！！！ 

晚安，那个学OI的我。 
*/  
