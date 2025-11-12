#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node {
	int a,b,c;
} t[N];

bool cmp(node x,node y) {
	return x.a>y.a;
}
int n;
int ans=0,flagb,flagc;
int vis[200][200][200]; 
void dfs(int x,int x1,int x2,int x3,int y) {
	if(x==n+1) {
		ans=max(ans,y);
//		cout<<ans<<endl;
		vis[x1][x2][x3]=ans;
		return ;
	}
	if(x1<n/2) {
		dfs(x+1,x1+1,x2,x3,y+t[x].a);
	}
	if(x2<n/2) {
		dfs(x+1,x1,x2+1,x3,y+t[x].b);
	}
	if(x3<n/2) {
		dfs(x+1,x1,x2,x3+1,y+t[x].c);
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>t[i].a>>t[i].b>>t[i].c;
			if(t[i].b!=0) flagb=1;
			if(t[i].c!=0) flagc=1;
			
		}
		if(flagb==0 && flagc==0) {
			sort(t+1,t+n+1,cmp);
			for(int k=1;k<=n/2;k++){
				ans+=t[k].a;
			}
		}
		else if(n<=200) dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}/*

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

1
4
4 0 0
10 0 0
8 0 0
1 0 0

这算是最后一次考试了，这么想来，从五年级到现在九年级，这个信息竞赛还是伴随了我很久
最开始想着通过这个当时看来前途广阔的赛道进入初中——锦城一中，但是最后还是没有考上
后面找了关系到了天府七中，到了才发现这是当时我第一次参加信息竞赛的地方
后面在第一次阶段考完，我给clz说了我有这方面的特长，但是当时她好像没有理会
倒是第一次参加csp初赛就没有过，当时教练也没有给名额，还是蛮可惜的，接近4年的竞赛路程
居然只参加了两次csp竞赛，后面好像是到了初一下半年，我也是成功加入了竞赛队，当时文化成绩
还不错所以想着就这样学学竞赛未来也许能考出去，所以当时周末一直都在上课，印象最深的一次是
当时数论章节的考试，我AK了全场，那也算我第一次意义上的AK也是最后一次，后来文化成绩下滑的厉害
后面已经达不到竞赛要求的基本成绩了，在考完最后一次直升考试后，还是选择放弃了竞赛

最后因为时间的匆忙只能写下这么多了
感谢我学竞赛以来遇到的所有
感谢李老师，感谢clz，感谢char，感谢当时一块在寝室里学习的队友们！
2025.11.1 
*/