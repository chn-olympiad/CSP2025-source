#include<bits/stdc++.h>
using namespace std;
int a[1000005][10];int bk[10];
struct lyc{
	int ca,id; 
}b[10000000];
int ans=0;int n;
void dfs(int step,int s,int aa,int bb,int cc)
{
	if(step>n)
	{
		ans=max(ans,s);
		return ;
	 } 
			if(aa<n/2)
			dfs(step+1,s+a[step][1],aa+1,bb,cc);
			if(bb<n/2)
			dfs(step+1,s+a[step][2],aa,bb+1,cc);
			if(cc<n/2)
			dfs(step+1,s+a[step][3],aa,bb,cc+1);
		
		
	
}
bool cmp(lyc x,lyc y)
{	if(x.ca==y.ca)
{
	return x.id<y.id;
}
	return x.ca>y.ca;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		
		ans=0;
		cin>>n;
		bk[2]=0;
		bk[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans+=a[i][1]; 
		}
		if(n<=20)
		{ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
					b[i].ca=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
					if(a[i][2]-a[i][1]>a[i][3]-a[i][1])
						b[i].id=2;
					else
						b[i].id=3;
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=b[i].ca; 
				bk[b[i].id]++;
			}
			for(int i=n/2+1;i<=n;i++)
			{
				if(b[i].ca>=0&&bk[b[i].id]<n/2)
				{
						ans+=b[i].ca;
						bk[b[i].id]++;
					
				}
				else
				if(b[i].ca<0)
				{
					break;
				}
			}
			cout<<ans<<endl;
		}
		
	}

}

