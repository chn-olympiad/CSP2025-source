#include<bits/stdc++.h>
using namespace std;
const int maxn=6*1e5,maxnn=1e6*8;
long long n,m,a[maxn],b[maxn],c[maxn],M,txx;
bool v[maxn];
vector<int>d[maxnn];
void find(long long st){
	txx++;
	if(txx>1000) return;
	if(st>M)
	{
		//cout<<txx<<endl;
		txx=0; 
		/*
		for(int i=0;i<=n;i++)
		{
			cout<<v[i];
		}cout<<"======"<<st<<endl;
		*/
	}
	
	
	
	M=max(M,st);
	for(int i=1;i<=n;i++)
	{
		if(v[i]||d[c[i]].empty()) continue;
		if(d[c[i]][d[c[i]].size()-1]<i)
		{
			if(v[d[c[i]][d[c[i]].size()-1]+1]) continue;
			bool f=0;
			for(int j=i-1;j>d[c[i]][d[c[i]].size()-1];j--)
			{
				if(v[j])
				{
					f=1;
					break;
				}
			}
			if(f) continue;
			//else
			for(int j=i;j>d[c[i]][d[c[i]].size()-1];j--)
				v[j]=1;
			find(st+1);
			for(int j=i;j>d[c[i]][d[c[i]].size()-1];j--)
				v[j]=0;
		}
		
		
		
		/*
		else if(d[c[i]][0]>i)
		{
			if(v[d[c[i]][0]]) continue;
			bool f=0;
			for(int j=i+1;j<d[c[i]][0];j++)
			{
				if(v[j])
				{
					f=1;
					break;
				}
			}
			if(f) continue;
			//else
			for(int j=i;j<=d[c[i]][0];j++)
				v[j]=1;
			find(st+1);
			for(int j=i;j<=d[c[i]][0];j++)
				v[j]=0;
		}
		*/
		
		
		
		else
		{
			long long q=-1;
			for(int j=i-1;j>=0;j--)//ÍùÇ°ÕÒ 
			{
				if(b[j]==c[i])
				{
					q=j;
					break;
				}
				if(v[j]) break;
			}
			if(q!=-1&&!v[q+1])
			{
				for(int j=i;j>q;j--)
					v[j]=1;
				find(st+1);
				for(int j=i;j>q;j--)
					v[j]=0;
			}
			/*
			q=-1;
			for(int j=i+1;j<=n;j++)//ÍùºóÕÒ 
			{
				if(v[j]) break;
				if(b[j]==c[i])
				{
					q=j;
					break;
				}
			}
			if(q!=-1)
			{
				for(int j=i;j<=q;j++)
					v[j]=1;
				find(st+1);
				for(int j=i;j<=q;j++)
					v[j]=0;
			}
			*/
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	d[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1] xor a[i];
		c[i]=b[i] xor m;
		d[b[i]].push_back(i);
		//cout<<c[i];/****************************************/
	}
	//cout<<(1 xor 3 xor 0)<<endl;/***************************/
	find(0);
	printf("%lld",M);
	
	return 0;
}
/*
*/
