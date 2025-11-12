#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;string timu;
int t[505];
int c[505];
int shunxv[505];

int plans=0;
void dfs(int p,ll total){
	if(p==n+1&&total>=m){
		plans++;plans%=998244353;return;
	}
	if(p==n+1)return;
	int jishu=0;
	for(int i=1;i<p;i++){
		if(t[i]<=0)jishu++;
	}
	for(int i=1;i<=n;i++){
		if(shunxv[i]==0){
			shunxv[i]=p;
			//cout<<"plan"<<plans<<" check "<<i<<" i_naixin="<<c[i]<<" jishu="<<jishu<<" total="<<total<<endl;
			if(c[i]>jishu){
				if(t[p]==1)dfs(p+1,total+1);
				else dfs(p+1,total);
			}
			else {
				t[p]-=1919810;
				dfs(p+1,total);
				t[p]+=1919810;
			}
			shunxv[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);

	cin>>n>>m>>timu;
	for(int i=1;i<=n;i++){cin>>c[i];shunxv[i]=0;t[i]=timu[i-1]-'0';}

	dfs(1,0);
	cout<<plans<<endl;

	return 0;
}
