#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10005][5],maxn,flag2,flag3,ans,a1[10005],a2[10005];
//long long dfsa(long long cnt,long long cnt1,long long cnt2,long long ansa)
//{
//	if(cnt1>maxn||cnt2>maxn)return 0;
//	if(cnt==n)return ans;
//	cnt1++;ansa+=a[cnt1][1];
//	dfsa(++cnt,++cnt1,cnt2,ansa);
//	cnt1--,cnt2++,ans-=a[cnt1+1][1],ansa+=a[cnt2][2];
//	dfsa(++cnt,cnt1,++cnt2,ansa);
//}
void dfs(long long cnt,long long cnt1,long long cnt2,long long cnt3,long long max_ans)
{
	//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<max_ans<<" "<<cnt<<endl;
	if(cnt1>maxn||cnt2>maxn||cnt3>maxn)
	{
		max_ans=0;return;
	}
	if(cnt==n)
	{
		
		ans=max(ans,max_ans);max_ans=0;return;
	}
	dfs(cnt+1,cnt1+1,cnt2,cnt3,max_ans+a[cnt+1][1]);
	dfs(cnt+1,cnt1,cnt2+1,cnt3,max_ans+a[cnt+1][2]);
	dfs(cnt+1,cnt1,cnt2,cnt3+1,max_ans+a[cnt+1][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;ans=0;maxn=n/2;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2])flag2=1;
			if(a[i][3])flag3=1;
		}
		if(!flag2&&!flag3)
		{
			for(int i=1;i<=n;i++) 
			{
				a1[i]=a[i][1];
			}
			sort(a1+1,a1+n+1);
			for(int i=n;i>=maxn;i--)
			{
				ans+=a1[i];
			}
			cout<<ans;
		}
//		else if(n==2)
//		{
//			int a1_1,a2_1,a1_2,a2_2,a1_3,a2_3;
//			a1_1=a[1][1],a2_1=a[2][1],a1_2=a[1][2],a2_2=a[2][2],a1_3=a[1][3],a2_3=a[2][3];
//			if(a1_1==a2_1==a1_2==a2_2==a1_3==a2_3)ans=a2_3+a2_3;
//			else //if(a1_1!=a1_3&&a1_1!=a1_2&&a2_2!=a2_3&&a2_2!=a2_1)
//			{
//				int maxa1i,maxa2i,maxa1i_2,maxa2i_2;
//				if(a1_1>=a1_2&&a1_1>=a1_3)maxa1i=1;
//				if(a1_2>=a1_1&&a1_2>=a1_3)maxa1i=2;
//				if(a1_3>=a1_2&&a1_3>=a1_1)maxa1i=3;
//				if(a2_1>=a2_2&&a2_1>=a2_3)maxa2i=1;
//				if(a2_2>=a2_1&&a2_2>=a2_3)maxa2i=2;
//				if(a2_3>=a2_2&&a2_3>=a2_1)maxa2i=3;
//				if(maxa1i==maxa2i)
//				{
//					if(maxa1i==1)a1_1=0,a2_1=0;
//					else if(maxa1i==2)a1_2=0,a2_2=0;
//					else if(maxa1i==3)a1_3=0,a2_3=0;
//					if(a1_1>=a1_2&&a1_1>=a1_3)maxa1i_2=1;
//					else if(a1_2>=a1_1&&a1_2>=a1_3)maxa1i_2=2;
//					else if(a1_3>=a1_2&&a1_3>=a1_1)maxa1i_2=3;
//					if(a2_1>=a2_2&&a2_1>=a2_3)maxa2i_2=1;
//					else if(a2_2>=a2_1&&a2_2>=a2_3)maxa2i_2=2;
//					else if(a2_3>=a2_2&&a2_3>=a2_1)maxa2i_2=3;
//					ans=max(a[1][maxa1i]+a[2][maxa2i_2],a[1][maxa1i_2]+a[2][maxa2i]);
//					//cout<<maxa1i<<maxa2i<<maxa1i_2<<maxa2i_2<<endl;
//				}
//				else ans=a[1][maxa1i]+a[2][maxa2i];
//			}
//		}
		else
		{
			
			dfs(0,0,0,0,0);
		} 
		cout<<ans<<endl;
	}	
	
	return 0;
}
/*
1 4
4 2 1
3 2 4
5 3 4
3 5 1
*/
