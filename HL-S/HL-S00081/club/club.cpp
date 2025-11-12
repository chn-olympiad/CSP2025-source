//#include <bits/stdc++.h>
//using namespace std;
//int cnt_a,cnt_b,cnt_c,n;
//bool vis[100005];
//struct node{
//	int num,id;
//};
//struct Change{
//	int num;
//	char ch;
//	int id;
//};
//int ans;
//node a[100005],b[100005],c[100005];
//Change change[5];
//bool cmp(node x,node y)
//{
//	return x.num>y.num;
//}
//bool cmp1(Change x,Change y)
//{
//	return x.num>y.num;
//}
//int bijiao(int step1,int step2,int step3)
//{
//	if(a[step1].num>b[step2].num&&a[step1].num>c[step3].num&&vis[a[step1].id]==0)
//	{
//		vis[a[step1].id]=1;
//		cnt_a++;
//		return 1;
//	}
//	else if(b[step2].num>a[step1].num&&b[step2].num>c[step3].num&&vis[b[step2].id]==0)
//	{
//		vis[b[step2].id]=1;
//		cnt_b++;
//		return 2;
//	}
//	else if(c[step3].num>a[step1].num&&c[step3].num>b[step2].num&&vis[c[step3].id]==0)
//	{
//		vis[b[step2].id]=1;
//		cnt_c++;
//		return 3;
//	}
//	else
//	{
//		if(a[step1].num==b[step2].num)
//			bijiao(step1++,step2++,step3);
//		else if(a[step1].num==c[step3].num)
//			bijiao(step1++,step2,step3++);
//		else if(b[step2].num==c[step3].num)
//			bijiao(step1,step2++,step3++);
//		else if(b[step2].num==c[step3].num&&a[step1].num==b[step2].num)
//			bijiao(step1++,step2++,step3++);
//	}
//	change[1].num=a[step1].num;
//	change[1].ch='a';
//	change[1].id=a[step1].id;
//	change[2].num=b[step2].num;
//	change[2].ch='b';
//	change[2].id=b[step2].id;
//	change[3].num=c[step3].num;
//	change[3].ch='c';
//	change[3].id=c[step3].id;
//	sort(change+1,change+4,cmp1);
//	return 0;
//}
//void solve(int step1,int step2,int step3)
//{
//	if(step1>(n/2)||step2>(n/2)||step3>(n/2))
//		return ;
//	int check=bijiao(step1,step2,step3);
//	if(check==1)
//	{
//		ans+=a[step1].num;
//		solve(step1++,step2,step3);
//	}
//	else if(check==2)
//	{
//		ans+=b[step2].num;
//		solve(step1,step2++,step3);
//	}	
//	else if(check==3)
//	{
//		ans+=c[step3].num;
//		solve(step1,step2,step3++);
//	}
//	else
//	{
//		vis[change[1].id]=1;
//		ans+=change[1].num;
//		if(change[1].ch=='a')
//		{
//			cnt_a++;
//			solve(step1++,step2,step3);
//		}
//		else if(change[1].ch=='b')
//		{
//			cnt_b++;
//			solve(step1,step2++,step3);
//		}
//		else
//		{
//			cnt_c++;
//			solve(step1,step2,step3++);	
//		}
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
////	freopen("club.in","r",stdin);
////    freopen("club.out","w",stdout);
//    int t;
//    cin>>t;
//    while(t--)
//    {
//    	memset(vis,0,sizeof(vis));
//    	ans=0;
//    	cin>>n;
//    	for(int i=1;i<=n;i++)
//    	{
//    		cin>>a[i].num>>b[i].num>>c[i].num;
//    		a[i].id=b[i].id=c[i].id=i;
//		}
//		sort(a+1,a+n+1,cmp);
//		sort(b+1,b+n+1,cmp);
//		sort(c+1,c+n+1,cmp);
//		solve(1,1,1);
//		cout<<ans;
//	}
//	return 0;
//}



#include <bits/stdc++.h>
using namespace std;
struct node{
	int num,id;
}a[100005],b[100005],c[100005];
unsigned long long ans;
bool vis[100005];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int flag=0;
    int n;
    while(t--)
    {
    	memset(vis,0,sizeof(vis));
    	ans=0;
    	cin>>n;
    	int flag1=0;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a[i].num>>b[i].num>>c[i].num;
    		if(c[i].num==0&&b[i].num==0&&flag==0)
    			flag=0;
    		else 
    			flag=1;
    		if(c[i].num==0&&b[i].num!=0&&flag1==0)
    			flag1=0;
    		else
    			flag1=1;
    		a[i].id=b[i].id=c[i].id=i;
		}
		if(flag==0)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].num;
			cout<<ans;
			return 0;
		}
		if(flag1==0)
		{
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			int cnt_a=0,cnt_b=0;
			if(a[cnt_a+1].num>=b[cnt_b+1].num&&vis[a[cnt_a+1].id]==false&&cnt_a+1<=n/2)
			{
				cnt_a++;
				ans+=a[cnt_a].num;
				vis[a[cnt_a].id]=1;
				
			}
			else if(b[cnt_b+1].num>a[cnt_a+1].num&&vis[b[cnt_b+1].id]==false&&cnt_b+1<=n/2)
			{
				cnt_b++;
				ans+=b[cnt_b].num;
				vis[b[cnt_b].id]=1;
			}
			cout<<ans;
		}
	}
	return 0;
}