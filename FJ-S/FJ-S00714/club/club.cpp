//我不行了，虚空调试1.5小时，还好；估分100
#include<bits/stdc++.h>
//#define DEBUG_LMCCSP
using namespace std;
int T;
int n;
int a[100010][4];
int choice[100010];
int arr[100010];
int sec[100010];
int cntt;
void count_second(int x)
{
	int maxx=0;
	int maxi;
	for(int i=1;i<=3;i++)
		if(i!=choice[x])
			if(a[x][i]>=maxx) maxx=a[x][i],maxi=i;
	sec[x]=maxi;
}
bool cmp(int x,int y)
{
	return (a[x][choice[x]]-a[x][sec[x]])<(a[y][choice[y]]-a[y][sec[y]]);
}
int did[100010];
int goal[100010]={0,147325,125440,152929,150176,158541};
int idk;
//void dfs(int i)
//{
//	if(i>n)
//	{
//		int tmp=0;
//		int cnt[4]={0,0,0,0};
//		for(int i=1;i<=n;i++)
//			tmp+=a[i][did[i]],cnt[did[i]]++;
////		cout<<endl;
////		system("pause");
//		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2) return;
////		cout<<tmp<<endl;
//		if(tmp==goal[idk]){
//			for(int i=1;i<=n;i++)
//				cout<<did[i]<<" ";
//		cout<<endl<<tmp<<endl<<endl;}
//		return;
//	}
//	did[i]=1;
//	dfs(i+1);
//	did[i]=2;
//	dfs(i+1);
//	did[i]=3;
//	dfs(i+1);
//}
main()
{
	ifstream cin("club.in",ios::in);
	ofstream cout("club.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
//	T=2;
	for(idk=1;idk<=T;idk++)
	{
		memset(a,0,sizeof a);
		memset(choice,0,sizeof choice);
		memset(arr,0,sizeof arr);
		memset(sec,0,sizeof sec);
		cntt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
//		if(idk==1) continue;
		int cnt[4]={0,0,0,0};
		int th=0;
		for(int i=1;i<=n;i++)
		{
			int maxx=0,maxi;
			for(int j=1;j<=3;j++)
				if(a[i][j]>=maxx) maxi=j,maxx=a[i][j];
			choice[i]=maxi;
			count_second(i);
			cnt[maxi]++;
			if(cnt[maxi]>(n/2)) th=maxi;
//			cout<<choice[i]<<" ";
		}
//		cout<<endl;
		
//		int tmp=0;
//		for(int i=1;i<=n;i++) tmp+=a[i][choice[i]];
//		cout<<tmp<<endl;
		
		if(th)
		{
			for(int i=1;i<=n;i++)
				if(choice[i]==th)
					arr[++cntt]=i;
			sort(arr+1,arr+cntt+1,cmp);
			for(int i=1,l=(cnt[th]-(n>>1));i<=l;i++)
				choice[arr[i]]=sec[arr[i]];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i][choice[i]];
//		cout<<endl;
		cout<<ans<<endl;
//		dfs(1);
//		dfs(1);
//		int cnt[4];
//		for(int i=1;i<=3;i++) cnt[i]=0;
//		for(int i=1;i<=n;i++)
//		{
//			choice[i]=1;
//			for(int j=2;j<=3;j++)
//			{
//				if(a[i][j]==a[i][choice[i]])
//					if(cnt[j]<cnt[choice[i]])
//						choice[i]=j;
//				if(a[i][j]>a[i][choice[i]])
//					choice[i]=j;
//			}
//			cnt[choice[i]]++;
//		}
//#ifdef DEBUG_LMCCSP
//		for(int i=1;i<=n;i++) cout<<choice[i]<<" ";
//		cout<<endl;
//#endif
//		if(cnt[1]<=(n>>1)&&cnt[2]<=(n>>1)&&cnt[3]<=(n>>1))
//		{
//			int ans=0;
//			for(int i=1;i<=n;i++) ans+=a[i][choice[i]];
//			cout<<ans<<endl;
//			continue;
//		}
//		int th;
//		for(int i=1;i<=3;i++) if(cnt[i]>(n>>1)) th=i;
//		int ans=0;
//		cntt=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(choice[i]!=th)
//				continue;
//			arr[++cntt]=i;
//			count_second(i);
//		}
//		sort(arr+1,arr+cntt+1,cmp);
//		for(int i=1;i<=(cnt[th]-(n>>1));i++)
//			choice[i]=sec[i];
//		for(int i=1;i<=n;i++) ans+=a[i][choice[i]];
//		cout<<ans<<endl;
	}
}
/*
最多只会有一堆超过n/2
对于这堆超过的：
把替换为第二大代价最小的多出来的换成第二大即可
因为每一个人绝对不会去第三的
最多也只能是一堆n/2，一堆n/2，一堆0
否则绝对不会超
*/
