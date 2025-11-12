#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int N=514;
const int MOD=998244353;
//const int M=1e6+114;
int n,m;
string s;
int c[N];
//int yes[N],no[N];
//int maxrej[N];
//vector<int>dp[N][N];//dp[i][j][t]:第i天选第j个人，前面no了t个人，当前排列组合可能 
//void init(){
//	memset(s,0,sizeof(s));
//	memset(c,0,sizeof(c));
//	n=m=0;
//}
//void solve(){
////	init();
//	cin>>n>>m;
//	int yesnum=0,nonum=0;
//	for(int i=1;i<=n;i++){
//		cin>>s[i];
//		yes[i]=yesnum;
//		no[i]=nonum;
//		if(s[i]==1){
//			yesnum++;
//		}
//		else nonum++;
//	}
//	for(int i=1;i<=n;i++){
//		cin>>c[i];
//	}
//	for(int i=1;i<=n;i++)
//	return;
//}
bool vis[N]={};
int dfs(int me,int no,int pos){
	if(s[pos]=='0'||no>=c[me])no++;
//	cout<<"me:"<<me<<"   no:"<<no<<"   pos:"<<pos<<endl;
	if(pos==n){
//		cout<<"***"<<(int)(n-no>=m)<<endl;
		if(n-no>=m) return 1;
		else return 0;
	}
	int ans=0;

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans+=dfs(i,no,pos+1);
			ans%=MOD;
			vis[i]=0;
		}
	}
	return ans;
}
void solve1(){
	cin>>n>>m;
	cin>>s;
	s="^"+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		ans+=dfs(i,0,1);
		ans%=MOD;
		vis[i]=0;
	}
	cout<<ans<<endl;
} 
signed main(){
	IOS
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve1();
	return 0;
}
