#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int rd(){int x=0,f=-1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int MAXN=1e5+10;
int n,a[MAXN],b[MAXN],c[MAXN],ans=0,d[MAXN];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int k){
	if(k==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(d[i]==1)sum+=a[i];
			if(d[i]==2)sum+=b[i];
			if(d[i]==3)sum+=c[i];
		}
		ans=max(ans,sum);
		return;
	}
	d[k]=1;
	dfs(k+1);
	d[k]=2;
	dfs(k+1);
	d[k]=3;
	dfs(k+1);
	return;
}
void solve(){
	cin>>n;
	bool flag1=1,flag2=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]; 
		if(c[i]!=0)flag1=0;
		if(c[i]!=0||b[i]!=0)flag2=0;
	}
	if(flag2){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)ans+=a[i];
		cout<<ans;
		return;
	}
	if(flag1){
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++)ans+=a[i];
		for(int i=1;i<=n;i++)c[i]=b[i]-a[i];
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n/2;i++)ans+=c[i];
		cout<<ans;
		return;
	}
	dfs(1);
	cout<<ans;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// finished at 16:58,qi wang de fen 40pts.
