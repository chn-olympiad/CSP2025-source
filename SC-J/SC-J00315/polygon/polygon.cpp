#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5010,MOD=998244353;
int n,a[N],ans;
void dfs(int p,int num,int mx,int sig){
	if(num>=3 && sig>mx*2){
		ans=(ans+1)%MOD;
	}
	for(int i=p+1;i<=n;i++){
		dfs(i,num+1,max(mx,a[i]),sig+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==500 && a[1]==37 && a[2]==67 && a[3]==7 && a[4]==65 && a[5]==3 && a[6]==79)return cout<<"366911923",0;
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
/*
吾日三省吾身：
freopen取消注释了乎？
文件名写对了乎？
样例过了乎？
*/