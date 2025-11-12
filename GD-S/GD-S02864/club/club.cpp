#include<bits/stdc++.h>
using namespace std;
struct student{
	int s1,s2,s3;//分别是三个社团的好感值
	int cc;//代表每个学生最喜欢和第二喜欢的社团的好感差 
};
student pp[100005];
int club[3][100005];//分别表示每个社团里面有编号为几的人 
int a,b,d[5];
long long ans;
int main(){//第二次考CSP提高组>v< 希望能拿个奖，不然信奥生涯就要终结了QwQ 
	freopen("club.in","r",stdin);//已经初三了。这场考完之后就准备退役了 
	freopen("club.out","w",stdout);//也感谢CCF给我这个机会，我会尽力的~ 
	scanf("%d",&a);
	while(a--){
		ans=0;
		scanf("%d",&b);
		memset(d,0,sizeof(d));//人数统计清零 
		memset(club,0,sizeof(club));//清空 
		memset(pp,0,sizeof(pp));
//		cout<<d[1]<<club[1][1]<<pp[1].s1<<endl;//测试 
		int m=b/2;//记录每个社团最多多少人 
		for(int i=1;i<=b;i++){
			scanf("%d%d%d",&pp[i].s1,&pp[i].s2,&pp[i].s3);//输入 
			int projecte[]={pp[i].s1,pp[i].s2,pp[i].s3},maxn;
			sort(projecte,projecte+3);//排序
			if(projecte[2]==pp[i].s1)maxn=1;
			if(projecte[2]==pp[i].s2)maxn=2;
			if(projecte[2]==pp[i].s3)maxn=3;//确定最喜欢的社团
			d[maxn]++;
			club[maxn][d[maxn]]=projecte[2]-projecte[1];//设置差值 
			ans+=projecte[2];//累加 
		}
		sort(&club[1][1],&club[1][d[1]+1]);
		sort(&club[2][1],&club[2][d[2]+1]);
		sort(&club[3][1],&club[3][d[3]+1]);//排序
//		for(int i=0;i<a;i++)
//		/*
		int check=0;//检查有没有超出的
		for(int i=1;i<=3;i++)if(d[i]>m)check=i;
		int f=1;
		while(d[check]>m){
			ans-=club[check][f];
			d[check]--;
			f++;
		}
		printf("%lld\n",ans);
//		*/
	}
	return 0;//最后两三分钟，已经检查过啦，也做不出什么了。最后等待奇迹吧。感谢CCF给我的这次机会。虽然我不知道我们还会不会相见 
}
