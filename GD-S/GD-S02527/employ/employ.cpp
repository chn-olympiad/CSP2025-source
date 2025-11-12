#include<bits/stdc++.h>
using namespace std;

int c[100005];
string s;
const int MOD=998244353

int dfs(int w){
	
}

bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1,cmp);
	if(c[2]<1 && m>1){
		cout<<0;
		return 0;
	}
	return 0;
}
