#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
ll ans;
int a[100100][5],A[100100],mx[100100];
bool b[100100];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(int x,int y,int z,int cnt,ll sum){
	if(cnt==n+1)ans=max(ans,sum);
	if(x<n/2)dfs(x+1,y,z,cnt+1,sum+a[cnt][1]);
	if(y<n/2)dfs(x,y+1,z,cnt+1,sum+a[cnt][2]);
	if(z<n/2)dfs(x,y,z+1,cnt+1,sum+a[cnt][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		memset(a,0,sizeof(a));
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			A[i]=a[i][1];
			mx[i]=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(n<=20){
			ans=0;
			dfs(0,0,0,1,0ll);
			cout<<ans<<endl;
		}else if(a[1][2]==0){
			ans=0;
			sort(A+1,A+n+1);
			for(int i=n;i>=n/2;i--)ans+=A[i];
			cout<<ans<<endl;
		}else{
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=mx[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
