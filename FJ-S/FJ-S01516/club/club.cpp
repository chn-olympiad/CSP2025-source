#include<bits/stdc++.h>
using namespace std;
int T,n;
struct Node{
	int x,y,z,pos;
	int dis;
	int cha;
}a[100100];
Node b[100100],c[100100];
int vis[100100];
vector<Node> v;
bool cmpx(Node i1,Node i2){
	return i1.cha>i2.cha;
}
bool cmpy(Node i1,Node i2){
	return i1.y>i2.y;
}
bool cmpd(Node i1,Node i2){
	return i1.dis>i2.dis;
}

int dfs(int pt,int k1,int k2,int k3,int som){
	if(k1+k2+k3==n){
		return som;
	}
	int maxn=som;
	if(k1<n/2) maxn=max(maxn,dfs(pt+1,k1+1,k2,k3,som+a[pt].x));
	if(k2<n/2) maxn=max(maxn,dfs(pt+1,k1,k2+1,k3,som+a[pt].y));
	if(k3<n/2) maxn=max(maxn,dfs(pt+1,k1,k2,k3+1,som+a[pt].z));
	return maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		v.clear();
		memset(vis,0,sizeof(vis));
		bool flag=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].x);scanf("%d",&a[i].y);scanf("%d",&a[i].z);
			a[i].pos=i;
			if(a[i].z) flag=0;
			b[i]=a[i];
			b[i].cha=b[i].x-b[i].y;
			c[i]=a[i];
			c[i].cha=c[i].y-c[i].x;
		}
		if(flag||n>250){
			sort(b+1,b+1+n,cmpx);sort(c+1,c+1+n,cmpx);
			int cnt=0,bi=1,ci=1,bs=0,cs=0,os=0;
			long long ans=0;
			while(cnt<n){
				while(vis[b[bi].pos]) bi++;
				while(vis[c[ci].pos]) ci++;
				if((cs*2==n)||(bs*2<n&&b[bi].cha>c[ci].cha)){
					cnt++;
					b[bi].dis=b[bi].z-b[bi].x;
					v.push_back(b[bi]);
					vis[b[bi].pos]=1;
					ans+=b[bi].x;//cout<<b[bi].x<<'*'<<endl;
					bi++;
					bs++;
					
				}else{
					cnt++;
					c[ci].dis=c[ci].z-c[ci].y;
					v.push_back(c[ci]);
					vis[c[ci].pos]=1;
					ans+=c[ci].y;//cout<<c[ci].y<<"&"<<endl;
					ci++;
					cs++;
				}
			}
			
			sort(v.begin(),v.end(),cmpd);
			int vp=0;
			while(vp*2<n&&v[vp].dis>0){
				ans+=v[vp].dis;
				vp++;
			}
			cout<<ans<<endl;
		}else{
			cout<<dfs(1,0,0,0,0)<<endl;
		}
	
	}
	fclose(stdin);
	fclose(stdout);
}
