#include <cstdio>
#include <utility> 
#include <algorithm>
#include <cstring>
using namespace std; 
//记得重置 
const int N = 2e5+5;
int t;
int n;
int shunx[3];//遍历顺序 
bool vis[N];
int ans;
int number_[3];
pair<int,int>club[3][N];
pair<int,int> clubshunx[3];
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline bool cmp(pair<int,int> a,pair<int,int>b)
{
	return a.first>b.first;
}
//int findmax(int a,int,b)
//{
//	return a>b;
//}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
//	printf("here");
	for(int k = 0; k<t;k++)
	{
		scanf("%d",&n);
		for(int i = 0 ; i< n ; i++)
		{ 
			scanf("%d%d%d",&club[0][i].first,&club[1][i].first,&club[2][i].first);//输入 
		}
		for(int i =0 ;i<n;i++)
		{
			club[0][i].second = i;
			club[1][i].second = i;
			club[1][i].second = i;//标记点 
		}
		sort(club[0],club[0]+n,cmp);
		for(int i = 0; i<int(n/2);i++)
		{
			ans+= club[0][i].first;
		}
		printf("%d\n",ans);
		ans = 0;
	}
	return 0;
}

//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <utility>
//using namespace std;
////记得重置数据 
//const int N = 1e5+5;
//int t_;//数据组数
//int n;//成员数量
//bool vis[N];// 标记是否已经选择俱乐部
//int ans;//先选第i个俱乐部的最大结果 
//int number_to[3];//三个俱乐部的成员计数 
//pair<int,int> to[3][N];
//inline bool sfcc(int num)
//{
//	return num>(n>>1);//比较是否超出 
//}
//inline bool cmp(pair<int,int> a,pair<int,int> b)
//{
//	return a.first>b.first;
//}
//inline int findmax(int a, int b,int c)
//{
//	int ans = max(c,max(a,b));
//	if(ans == a)return 0;
//	if(ans == b)return 1;
//	if(ans == c)return 2; 
//}
//int main()
//{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	scanf("%d",&t_);
//	for(int k = 0 ; k< t_;k++)
//	{
//		scanf("%d",&n);
//		for(int i = 0;i<n;i++)
//		{
//			scanf("%d%d%d",&to[0][i].first,&to[1][i].first,&to[2][i].first);
//		}
//		for(int i = 0 ;i<n;i++)
//		{
//			to[0][i].second = to[1][i].second = to[2][i].second = i;
//		}
//		for(int i = 0;i<3;i++)
//			sort(to[i],to[i]+n,cmp);
//		
//		int firstclub = findmax(to[0][0].first,to[1][0].first,to[2][0].first);
//		int cnt = 0;//记住访问的点数 
//		while(cnt != n)
//		{
//			int vis_num = number_to[firstclub];
//			int vis_num2 = to[firstclub][vis_num].second;
//			while(1)
//			{
//				if(vis[vis_num2])
//				{
//					vis_num2+=1;
//				}
//				else break;
//				printf("这个点%d是我要的",vis_num2);
//				
//			}
//			ans += to[firstclub][vis_num2].first;//
//			number_to[firstclub] ++;
//			cnt++;
//			if(firstclub == 0)
//			{
//				firstclub = 1;
//				continue; 
//			 } else if(firstclub == 1)
//			 {
//			 	firstclub = 1;
//				continue; 
//			 }
//			 else 
//			 {
//			 	firstclub = 2;
//				continue; 
//			 }
//		}
//		printf("%d",ans);
////		for(int i = 0 ; i< n; i++)
////		printf("%d ",a_[i].to1);
////		for(int j = 0 ;j <n;j++)
////		{
////			 if(vis[i])continue;
//		
////		}
////		f_[0] += a_[0].to1; 
////		vis[0] = true;//标记为访问 
////		int j = 0;
////		while(vis[j])j++;
////		if(!vis[j])f_[0] += a_[0].to2;//第二个俱乐部 
////		vis[j] = true;//标记为访问 
////		j = 0;
////		while(vis[j])j++;
////		if(!vis[j])f_[0] += a_[0].to3;//第三个俱乐部 
////		vis[j] = true;//标记为访问 
//		
//	}
//	
////	for(int i = 0 ; i< n; i++)
////		printf("%d ",a_[i]);
//	
//	
//	return 0;
//} 
////	sort(a_,a_+n,cmp1);
//////			while(vis[j])j++;
////			int l_;
////			for(int l = 0;l<n;l++)
////			{
////				if(vis[a_[l].id])continue;
////				ans += a_[l].to1;  
////				l_ = l;
////				break;
////			}
////			printf("ato1:%d\n",a_[l_].to1);
////			vis[a_[l_].id] = true;//标记为访问 
////			cnt++; 
////			number_to[0] ++; 
////			if(cnt == n)break;
////			l_ = 0;
////			
////			sort(a_,a_+n,cmp2);
//////			while(vis[j])j++;
////			for(int l = 0;l<n;l++)
////			{
////				if(vis[a_[l].id])continue;
////				ans += a_[l].to2;  
////				break;
////			}
////			printf("ato2:%d\n",a_[l_].to2);
////			vis[a_[l_].id] = true;//标记为访问 
////			cnt++; 
////			number_to[1] ++; 
////			if(cnt == n)break;
////			l_ = 0;
////			
////			sort(a_,a_+n,cmp3);
//////			while(vis[j])j++;
////			for(int l = 0;l<n;l++)
////			{
////				if(vis[a_[l].id])continue;
////				ans += a_[l].to3;  
////				break;
////			}
////			printf("ato3:%d\n",a_[l_].to3);
////			vis[a_[l_].id] = true;//标记为访问 
////			cnt++; 
////			number_to[2] ++; 
////			if(cnt == n)break;
////			l_ = 0;
////			
////		 } 
////		 printf("%d\n",ans);
////		 ans = 0;
////		 memset(a_,0,sizeof(a_));
////		 memset(vis,false,sizeof(vis));
////		 n = 0;
