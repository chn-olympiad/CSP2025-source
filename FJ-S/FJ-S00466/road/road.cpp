#include<bits/stdc++.h>
#define N 20050
#define M 1000050
#define K 15
using namespace std;
struct Data{int x,y,z;}w[M];
int n,m,k,a[K][N],f[M];
long long ans=1e18;
bool cmp(Data x,Data y){return x.z<y.z;}
vector<Data>v;
int fa(int x)
{
	if(x==f[x]) return x;
	return f[x]=fa(f[x]);
}
long long fun(int sz)
{
	int p1=1,p2=0,cnt=n+sz;
	long long res=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	w[m+1].z=1e9+7;
	v.push_back({0,0,1e9+7});
//	cout<<"[w]"<<endl;
//	for(int i=1;i<=m;i++) cout<<w[i].x<<" "<<w[i].y<<" "<<w[i].z<<endl;
//	cout<<"[v]"<<endl;
//	for(auto now:v) cout<<now.x<<" "<<now.y<<" "<<now.z<<endl;
	while(1)
	{
		if(p1==m+1&&p2==v.size()) break;
		if(cnt==1) break;
		int x,y,z;
//		cout<<p1<<" "<<p2<<endl;
		if(p1==m+1||v[p2].z<w[p1].z)
		{
			x=fa(v[p2].x),y=fa(v[p2].y),z=v[p2].z;
			p2++;
			if(x==y) continue;
			f[x]=y;
			res+=z;
			cnt--;
		}
		else
		{
			x=fa(w[p1].x),y=fa(w[p1].y),z=w[p1].z;
			p1++;
			if(x==y) continue;
			f[x]=y;
			res+=z;
			cnt--;
		}
	}
	return res;
}
bool subtask()
{
	for(int i=1;i<=k;i++) if(a[i][0]) return 0;
	return 1;
}
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	return x;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) w[i].x=read(),w[i].y=read(),w[i].z=read();
	sort(w+1,w+m+1,cmp);
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) a[i][j]=read();
	int st=0;
	if(subtask()) st=(1<<k)-1;
	for(int s=st;s<(1<<k);s++)
	{
		int cnt=0;
		long long sum=0;
		v.clear();
		for(int i=1;i<=k;i++)
		{
			if(!(s&(1<<i-1))) continue;
//			if(!(1&(1<<i-1))) continue;
			for(int j=1;j<=n;j++) v.push_back({n+i,j,a[i][j]});
			sort(v.begin(),v.end(),cmp);
			sum+=a[i][0];
			cnt++;
		}
		ans=min(ans,sum+fun(cnt));
	}
	cout<<ans;
//	sort(w+1,w+m+1,cmp);
	return 0;
}

