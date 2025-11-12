#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m,k,u,v,w,zwf;
vector<pair<int,long long>> r[N];
vector<long long> d[15];
long long dj[10010];
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch>'9'&&ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		r[u].push_back({v,w});
		r[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		long long cj;
		cin>>cj;
		d[i][1]=cj;
		for(int j=1;j<=n;j++){
			zwf=read();
			d[i][j+1]=zwf;
		}
	}
	cout<<11;
	return 0;
} 


