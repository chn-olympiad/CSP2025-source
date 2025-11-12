#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n,maxx,ans=-1;
int stu[5][N];
bool vis[5][N];
void dfs(int tot,int ch,int ac,int bc,int cc) {
	if(ch>n && !(ac>maxx || bc>maxx || cc>maxx)) {
		ans=max(ans,tot);
		return ;
	}
	if(ac>maxx || bc>maxx || cc>maxx) {
		return ;
	}
	for(int i=1;i<=3;i++) {
		if(!vis[i][ch]) {
			vis[1][ch]=vis[2][ch]=vis[3][ch]=1;
			if(i==1) dfs(tot+stu[i][ch],ch+1,ac+1,bc,cc);
			else if(i==2) dfs(tot+stu[i][ch],ch+1,ac,bc+1,cc);
			else if(i==3) dfs(tot+stu[i][ch],ch+1,ac,bc,cc+1);
			vis[1][ch]=vis[2][ch]=vis[3][ch]=0;
		}
	}
}

void solve()
{
	cin>>n;
	maxx=(n>>1);
	ans=-1;
	for(int i=1;i<=n;i++) {
		cin>>stu[1][i]>>stu[2][i]>>stu[3][i];
	}
	
	dfs(0,1,0,0,0);
	
	cout<<ans<<"\n";
	
	///sort(a+1,a+1+n,cmp1);
	
	//		cout<<pai[i][j]<<' ';
	//	cout<<"\n";
	//}
	
}
int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--) solve();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}