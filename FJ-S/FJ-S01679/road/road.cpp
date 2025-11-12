#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[500005];
long long cnt=1,sum=0;
long long s[5000005];
long long find(long long x){
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
long long con(long long x,long long y){
	long long xx=find(x);
	long long yy=find(y);
	if(xx!=yy)
	{
		fa[yy]=xx;
//		cout<<x<<" "<<y<<"\n";
		cnt++;
		return 1;
	}
	return 0;
}

struct note{
	long long u,v,w;
}a[700005];
long long cmp(note x,note y){
	return x.w<y.w;
}


int main(){
//	freopen("road1.in","r",stdin);
//	freopen("road1.ans","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	long long num=m;
	for(int j=1;j<=k;j++)
	{
		long long c;
		cin>>c;
		for(int i=1;i<=n;i++)
		{
//			long long s;
			cin>>s[i];
//			long long J=j,I=i;
			 ///////////////////////////////////////////////////////////////
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=j)
			{
				num++;
				a[num].u=j;
				a[num].v=i;
				a[num].w=c+s[j]+s[i];
			}
		}
	}
	sort(a+1,a+1+num,cmp);
//	for(int i=1;i<=num;i++)
//	{
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
//	}
//	cout<<"\n";
	for(int i=1;i<=num;i++)
	{
		if(cnt==n)
		{
			cout<<sum;
			break;
		}
		if(con(a[i].v,a[i].u)==1)
		{
			sum+=a[i].w;
		}
		
		
		
	}
	return 0;
} 
