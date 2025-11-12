#include<bits/stdc++.h>
#define ll long long
#define endl '\n' 
using namespace std;
const int N=1e5+2;
int n,ans;
struct node{
	int val,p;
}a[N],b[N],c[N];
void dfs(int p,int x,int y,int z,int sum){
	if(p==n+1){
		ans=max(ans,sum);
		return;
	}
	if(x<n/2){
		dfs(p+1,x+1,y,z,sum+a[p].val);
	}
	if(y<n/2){
		dfs(p+1,x,y+1,z,sum+b[p].val);
	}
	if(z<n/2){
		dfs(p+1,x,y,z+1,sum+c[p].val);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].val>>b[i].val>>c[i].val;
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
吾日三省吾身：
freopen取消数值了乎？
文件名写对了乎？
样例过了乎？
*/