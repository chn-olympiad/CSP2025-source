#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100005][5],ans;
int f[100005][5],d[100005][5][5];
int x1,x2,x3;
int read(){
	char ch=getchar();int w=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
}
void dfs(int x,int s){
	if(x==n+1){
		ans=max(ans,s);
		return ;
	}
	if(x1+1<=n/2){
		x1++;
		dfs(x+1,s+a[x][0]);
		x1--;
	}
	if(x2+1<=n/2){
		x2++;
		dfs(x+1,s+a[x][1]);
		x2--;
	}
	if(x3+1<=n/2){
		x3++;
		dfs(x+1,s+a[x][2]);
		x3--;
	}
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		ans=x1=x2=x3=0;
		n=read();
		bool flag=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				a[i][j]=read();
			if(a[i][1]||a[i][2])
				flag=1;
		}
		if(flag==0){
			priority_queue<int>q;
			for(int i=1;i<=n;i++)
				q.push(a[i][0]);
			for(int i=1;i<=n/2;i++)
				ans+=q.top(),q.pop();
			cout<<ans<<endl;
			continue;
		}
		if(n<=16){
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					if(f[i-1][k]+a[i][j]>f[i][j])
						f[i][j]=f[i-1][k]+a[i][j],d[i][j][j]=d[i-1][k][j]+1;
		for(int j=0;j<3;j++)
			if(d[n][j][j]<=n/2&&d[n][j][(j+1)%3]<=n/2&&d[n][j][(j-1)%3]<=n/2)
				ans=max(ans,f[n][j]);
		cout<<ans<<endl;
	}
	return 0;
}
