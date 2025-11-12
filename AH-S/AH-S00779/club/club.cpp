#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n, m, T, ans, k, dp[N][4], a[N][4], t[4], b[N], c[N];
vector<int> e[N];
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T=read();
	while(T--)
	{
		memset(dp, 0, sizeof dp);
		memset(t, 0, sizeof t);
		n=read();
		k=n/2;
		bool pd1=1;
		ans=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++)
				a[i][j]=read();
			b[i]=a[i][1];
			if(a[i][3]!=0||a[i][2]!=0) pd1=0;
		}
		if(pd1){
			for(int i=1; i<=n/2; i++) ans+=b[i];
			cout<<ans<<endl;
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++){
				if(t[j]<k) dp[i][j]=max(dp[i][j-1], dp[i][j-1]+a[i][j]), t[j]++;
				else dp[i][j]=max(dp[i][j-1], dp[i][j-1]+a[i][j]);
			}
		}
		cout<<dp[n][3]<<endl;
		
	}
	return 0;
}
