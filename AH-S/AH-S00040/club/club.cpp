#include <bits/stdc++.h>
using namespace std;
int t,n;
int maxtot;
unsigned long long ans,res;
int tot[5];
struct stu
{
	int value[5];
	bool joined;
}a[100050];
void dfs(int pos)
{
    if(pos==n)
    {
		if(res>ans) ans=res;
		return ;
	}
    else
    {
		for(int j=1;j<=3;j++)
		{
			if(a[pos].joined==0&&tot[j]<maxtot)
			{
				a[pos].joined=1;
				tot[j]++;
				res+=a[pos].value[j];
			    dfs(pos+1);
			    a[pos].joined=0;
			    tot[j]--;
			    res-=a[pos].value[j];
			}
		}
	}	
	return ;
}
void tepan()
{
	int yihao[5];
	int erhao[5];
	cin>>yihao[1]>>yihao[2]>>yihao[3]>>erhao[1]>>erhao[2]>>erhao[3];
	int anstp,anstpm;
	for(int i=1;i<=3;i++) 
	{
		for(int j=1;j<=3;j++)
		{
			if(i==j) continue;
			anstp=yihao[i]+erhao[j];
			if(anstp>anstpm) anstpm=anstp;
		}
	}
	cout<<anstpm<<endl;
	return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int s=1;s<=t;s++)
    {
		memset(tot,0,sizeof(tot));
		memset(a,0,sizeof(a));
		ans=0;res=0;
		cin>>n;maxtot=n/2;
		if(n==2){tepan();continue;}
		for(int i=0;i<n;i++) 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i].value[j];
				a[i].joined=0;
			}
			
		}
		dfs(0);
		cout<<ans<<endl;
	}	
    return 0;
}
