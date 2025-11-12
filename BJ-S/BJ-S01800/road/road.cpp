#include<bits/stdc++.h>

using namespace std;
void read(int &x){
	x=0;
	int fla=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')fla=1;
	x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';
	if(fla)x=-x;
	return;
}
const int N=2e4+5;
struct node{
	int x,y,z;
	bool operator <(const node &zzz)const{
		return z<zzz.z;
	}
};
vector<node>v,v2;
int fa[N];
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	fa[getfa(x)]=getfa(y);
	return;
}
int w[100],flag[100],pos[100],now[N];
node a[13][N];
bool check(node x){
	return getfa(x.x)!=getfa(x.y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	read(n);read(m);read(k);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(x);read(y);read(z);
		v.push_back((node){x,y,z});
	}
	sort(v.begin(),v.end());
	int cnt=n,vk=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	while(cnt>1){
		if(check(v[vk])){
			v2.push_back(v[vk]);
			merge(v[vk].x,v[vk].y);
			ans+=v[vk].z;
			cnt--;
		}
		vk++;
	}
	for(int i=1;i<=k;i++){
		read(w[i]);
		flag[i]=w[i];
		for(int j=1;j<=n;j++){
			int x;
			read(x);
			a[i][j]=(node){j,i+n,x};
		}
		sort(a[i]+1,a[i]+1+n);
	}
	for(int i=1;i<(1<<k);i++){
		//cout<<i<<endl;
		vk=0;int u=0;
		long long sum=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1)))pos[++u]=j,sum+=w[j];now[j]=1;
		}
		for(int j=1;j<=n+k;j++)fa[j]=j;
		cnt=n+u;
		while(cnt>1){
			int minn,po=0;
			if(vk!=v2.size())minn=v2[vk].z;
			else minn=2e9+1;
			for(int j=1;j<=u;j++){
				if(now[pos[j]]<=n&&a[pos[j]][now[pos[j]]].z<minn){
					minn=a[pos[j]][now[pos[j]]].z;
					po=pos[j];
				}
			}
			if(po){
				node zz=a[po][now[po]];
				if(check(zz)){
					sum+=zz.z;
					merge(zz.x,zz.y);
					cnt--;
				}
				now[po]++;
			}else{
				if(check(v2[vk])){
					sum+=v2[vk].z;
					merge(v2[vk].x,v2[vk].y);
					cnt--;
				}
				vk++;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
//g++ b.cpp -o b -std=c++14 -static -Wall