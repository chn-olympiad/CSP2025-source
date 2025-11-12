//GZ-S00100   遵义市第四中学   周俊翰 
#include <bits/stdc++.h>
#define maxn 998244353
#define ll long long
using namespace std;
int dp[503];
ll n,m,ans=0;
ll d[502],t=0,e[502],n1=0;
ll c[503],p;
string a;
void dfs(int x,int y){
	if(x==n&&y>=m){
		ans++;
		ans%=maxn;
		return;
	}
	if(x!=0) if(n1-e[x-1]<m-y){
		//cout << x << " ";
		return;
	}
	for(int i=0;i<n;i++){
		//if(dp[x][c[i]]!=0){
		//	ans+=dp[x][c[i]];
		//	continue;
		//}
		if(dp[i]==1){
			continue;
		}
		if(c[i]>d[x]&&a[x]=='1'){
		//	cout << i << " ";
			dp[i]=1;
			//cout << i << " ";
			dfs(x+1,y+1);
			dp[i]=0;
			//dp[x][c[i]]=ans;
		}
		else{
			dp[i]=1;
			dfs(x+1,y);
			dp[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			n1++;
		}
	}
	if(n1<m){
		printf("0");
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	sort(c,c+n);
	//for(int i=0;i<n;i++){
	//	cout << c[i] << " ";
	//}
	n1=0;
	d[0]=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			d[i]=d[i-1]+1;
			e[i]=e[i-1];
		}
		else{
			n1++;
			d[i]=d[i-1];
			e[i]=e[i-1]+1;
		}
	}
	dfs(0,0);
	fclose(stdin);
	fclose(stdout);
	cout << ans;
	return 0;
}
