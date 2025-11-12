#include<bits/stdc++.h>
using namespace std;
int f[10100010];
struct re{
	int x;
	int y;
	int z;
}op[1010100];
int cnt;
void fun(int x,int y,int z){
	op[++cnt]=re{x,y,z};
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(x);
}
bool cmp(re a,re b){
	return a.z<b.z;
}
int mp[3031][3030];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T;
	int n,m,k;
	cin>>n>>m>>k;
	long long ans=0,sum=0;
	if(k==0){
		for(int i=1;i<=n;i++)f[i]=i;
		fun(0,1,0);
        for(int i=1;i<=m;i++){
            int x;int y;int z;
            cin>>x>>y>>z;
            fun(x,y,z);
        }
        sort(op+1,op+m+1,cmp);
		for(int i=1;i<=m;i++){
            re l=op[i];
            if(find(l.x)!=find(l.y)){
                int xl=find(l.y);
                int yl=find(l.x);
				f[xl]=yl;
                ans+=l.z;
                sum++;
            }
            if(sum==n)break;
        }
        cout<<ans<<'\n';        
	}
	else {
	for(int i=1;i<=n;i++)f[i]=i;
	memset(mp,0x3f3f,sizeof mp);
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		//fun(x,y,z);
		mp[min(x,y)][max(x,y)]=min(z,mp[min(x,y)][max(x,y)]);
	}
	int c[1010];
	int p[20][10010];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>p[i][j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				mp[j][k]=min(mp[j][k],p[i][j]+p[i][k]);
			}
		}
	}
	f[0]=0;
	fun(0,1,0);
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp[i][j]!=0x3f3f)fun(i,j,mp[i][j]);
		}
	}
	sort(op+1,op+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		re l=op[i];
		if(find(l.x)!=find(l.y)){
			ans+=l.z;
			f[find(l.y)]=f[find(l.x)];
			++sum;
		}
		if(sum==n)break;
	}
	}
	cout<<ans;
	return 0;
}

