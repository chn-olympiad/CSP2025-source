#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int T=998244353;
const int maxn=5e2+2;
int n,m,ans=0;
char s[maxn];
int c[maxn];
bool vis[maxn];
void solve1(int q,int cnt,int sum){//当前是第q个人，当前是第cnt天，总共有sum人放弃 
	if (cnt==n){
		if (sum>=c[q] || s[cnt]=='0')
			sum++;
		if (m<=n-sum){
			ans++;
			return;
		}
	}
	if (m>n-sum)
		return;
	vis[q]=true;
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=true;
			solve1(i,cnt+1,sum+(sum>=c[i] || s[cnt]=='0'));
		}
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	for (int i=1;i<=n;i++)
		cin>>c[i];
	if (m==n){
		cout<<"0";
		return 0;
	}
	if (m==1){
		cout<<n;
		return 0;
	}
	solve1(0,1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
