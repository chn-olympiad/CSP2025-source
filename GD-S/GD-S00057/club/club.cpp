/*
	RP++!
	freopen!!!(last year CSP-J -100pts)
	
	14:41 start solving T1 
	15:23 T1 AC!!! happy
	15:25 Is T2 MST?
	15:30 Yes.
	16:06 solving T2.
	wo shijianfuzadu cuode yitahutu.
	xiangqi le Xor-MST CF888G
	wo jide yige B kaitou de suanfa
	jianbian yingai xiangcuole...
	ohno.i'm sooooooooo sad.
	16:15 youren shuizhaole???
	16:17 couhe yong ba.pian dian fen.
	(wangji Bouxxxxx zenme xie le)
	16:25 juewang le.2 hours left
	16:42 T2 32pts goodbye TAT
	i cant do more pts.
	today only 2=
	what's T3 talking about???i cant understand it
	17:07 T4 pianfen zhong...
	17:20 T4 get feature A 20pts! goodbye~
	solving T3...
	17:32 hao e a...
	weishenme buneng dai dongxi jinlai chi???
	qunian wo jide keyi a.
	17:47 T3 pianfen zhong...
	18:01 done.kaishi jiancha.
	
	fangkuimo hao hu,kuai xiale...
	zheci tiede jiaodai yandoubuyanle,
	zhijie ba renwulan dangzhule.
	
	jiankao laoshi yifu shang yinzhe It's MYGO!!!
	
	zaogao!wo bei HSFZers baowei le!(both J&S)
	and EZers&GDFers.
	
	sto lny orz
	sto dsw orz
	sto EZ dalao orz
	lny will S 1=
	lny has J 1=
	dsw will S 1=
	dsw got J 320
	lny qing baoyou wo S 1=
	dsw qing baoyou wo S 1=
	
	wo bu hui,zhang da hou zai xue xi!
	
	shuxi de jilu fangshi..
	I'm GD-J00054!
	qing guanzhu luogu 845367 @__QWQ_qwq__ ! 
*/
#include<bits/stdc++.h>
using namespace std;
int n,ans[4],cnt[4];
struct stu{
	int x,y,z,lv1=0,lv2=0;
	int rk1,rk2;
}a[100010];
bool cmp(stu a,stu b)
{
	if(a.lv1-a.lv2!=b.lv1-b.lv2) return a.lv1-a.lv2>b.lv1-b.lv2;
	return a.lv1>b.lv1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(ans,0,sizeof ans);
		memset(cnt,0,sizeof cnt);
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].lv1=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].lv1==a[i].x)
			{
				a[i].rk1=1;
				if(a[i].y>a[i].z) a[i].lv2=a[i].y,a[i].rk2=2;
				else a[i].lv2=a[i].z,a[i].rk2=3;
			}
			else if(a[i].lv1==a[i].y)
			{
				a[i].rk1=2;
				if(a[i].x>a[i].z) a[i].lv2=a[i].x,a[i].rk2=1;
				else a[i].lv2=a[i].z,a[i].rk2=3;
			}
			else if(a[i].lv1==a[i].z)
			{
				a[i].rk1=3;
				if(a[i].y>a[i].x) a[i].lv2=a[i].y,a[i].rk2=2;
				else a[i].lv2=a[i].x,a[i].rk2=1;
			}
		}
		//qiu mx/sec
		
		
		sort(a+1,a+n+1,cmp);//paixu
		
		
//		for(int i=1;i<=n;i++)
//		{
//			cout<<i<<" ";
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z;
//			cout<<endl;
//		}


		for(int i=1;i<=n;i++)
		{
			if(cnt[a[i].rk1]==n/2)
			{
				cnt[a[i].rk2]++;
				if(a[i].rk2==1) ans[a[i].rk2]+=a[i].x;
				else if(a[i].rk2==2) ans[a[i].rk2]+=a[i].y;
				else ans[a[i].rk2]+=a[i].z;
			}
			else
			{
				cnt[a[i].rk1]++;
				if(a[i].rk1==1) ans[a[i].rk1]+=a[i].x;
				else if(a[i].rk1==2) ans[a[i].rk1]+=a[i].y;
				else ans[a[i].rk1]+=a[i].z;
			}
		}
		//solve
		
		int res=0;
		for(int i=1;i<=3;i++) res+=ans[i];
		cout<<res<<endl;
		//out
	}
}
