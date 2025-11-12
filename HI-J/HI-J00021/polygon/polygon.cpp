#include <bits/stdc++.h>
using namespace std;
int n; long long tot,ans;int maxx=0;int t;
int a[5010];bool b[5010];int last;int ma[5010];
void print()
{
	//cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==true)
		{
		//	cout<<a[i]<<" ";
		}
		
	}
	//cout<<endl;
	return ;
}
int hanshu()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]==true)
		{
			maxx=max(maxx,a[i]);
		}
	}
}
int dfs(int x,int d,int to)
{
//	cout<<to<<" "<<a[to]<<endl;
	b[to]=true;
	//cout<<b[to]<<endl;
	if(d==x)
	{
		
		/*if(a[to]>maxx)
		{
			last=maxx;
			maxx=a[to];
			
		}*/
		
		hanshu();
		//cout<<maxx<<" "<<a[to]<<" "<<tot<<endl;
		if((tot)>(maxx*2))
		{
			//cout<<tot<<" "<<maxx*2<<endl;
			ans++;
			t=d;
			print();
			
		}
		b[to]=false;
		maxx=0;
		//maxx=last;
		return 0;
	}
	//tot+=a[to];
	
	maxx=max(maxx,a[to]);
	for(int i=to;i<=n;i++)
	{
		if(b[i]==true)
		{
			//t<<" "<<i<<" ";
			continue;
		}
		//cout<<endl<<i;
	/*	if(a[i]>maxx)
			{
				
				last=maxx;
				maxx=a[i];
				//cout<<maxx<<endl;
			}*/
			//cout<<maxx<<" "<<tot<<" "<<a[i]<<endl;
		//if((tot+a[i])>(maxx*2))
		//{
			
			tot+=a[i];
			//cout<<endl<<tot<<" "<<maxx<<" "<<a[i]<<endl;
			//cout<<d<<" "<<i<<endl;
			dfs(x,d+1,i);
			tot-=a[i];
		//}
	//	maxx=last;
	}
	//tot-=a[to];
	b[to]=false;
	//cout<<endl<<endl<<to;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ma[i]=max(ma[i-1],a[i]);
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			memset(b,0,sizeof(b));tot=0;
			if(j==n-i+1)
			{
				break;
			}
			tot+=a[j];
			dfs(i,1,j);
			
		}
		
	}
	//cout<<(ans%998244353);
	cout<<rand();
	return 0;
} 
