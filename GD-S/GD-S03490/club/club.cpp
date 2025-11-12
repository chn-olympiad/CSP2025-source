#include<iostream>
#include<queue>
using namespace std;
int n,t;
struct hjj
{
	int num,lie,maxn;
	bool operator <(hjj k) const{
		return maxn>k.maxn;
	}
};
priority_queue<hjj>lqq1;
priority_queue<hjj>lqq2;
priority_queue<hjj>lqq3;
int a1[100015],a2[100015],a3[100015];
int cnt1,cnt2,cnt3;
long long ans,shu;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cnt1=cnt2=cnt3=0;
		ans=0;
		while(!lqq1.empty())lqq1.pop();
		while(!lqq2.empty())lqq2.pop();
		while(!lqq3.empty())lqq3.pop();
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		for(int i=1;i<=n;i++)
		{
			ans+=max(a1[i],max(a2[i],a3[i]));
			if(a1[i]>a2[i]&&a1[i]>a3[i])
			{
				lqq1.push((hjj){a1[i],i,a1[i]-max(a2[i],a3[i])});
				cnt1++; 
			}
			else if(a2[i]>a1[i]&&a2[i]>a3[i])
			{
				lqq2.push((hjj){a2[i],i,a2[i]-max(a1[i],a3[i])});
				cnt2++;
			}
			else
			{
				lqq3.push((hjj){a3[i],i,a3[i]-max(a1[i],a2[i])});
				cnt3++;
			}
		}
		int wei; 
		while(cnt1>n/2)
		{
			wei=lqq1.top().lie;
			if(a2[wei]>a3[wei])
			{
				lqq2.push((hjj){a2[wei],wei,a1[wei]-a3[wei]});
				cnt2++;
			}
			else
			{
				lqq3.push((hjj){a3[wei],wei,a1[wei]-a2[wei]});
				cnt3++;
			} 
			ans-=a1[wei];
			ans+=max(a2[wei],a3[wei]);
			cnt1--;
			lqq1.pop();
		}
		while(cnt2>n/2)
		{
			wei=lqq2.top().lie;
			if(a1[wei]>a3[wei])
			{
				lqq1.push((hjj){a1[wei],wei,a2[wei]-a3[wei]});
				cnt1++; 
			}
			else
			{
				lqq3.push((hjj){a3[wei],wei,a2[wei]-a1[wei]});
				cnt3++;
			} 
			ans-=a2[wei];
			ans+=max(a1[wei],a3[wei]);
			cnt2--;
			lqq2.pop();
		}		
		while(cnt3>n/2)
		{
			wei=lqq3.top().lie;
			if(a2[wei]>a1[wei])
			{
				lqq2.push((hjj){a2[wei],wei,a3[wei]-a1[wei]});
				cnt2++;
			}
			else
			{
				lqq1.push((hjj){a1[wei],wei,a3[wei]-a2[wei]});
				cnt1++; 
			} 
			ans-=a3[wei];
			ans+=max(a2[wei],a1[wei]);
			cnt3--;
			lqq3.pop();
		}
		cout<<ans<<endl;
	}
} 
