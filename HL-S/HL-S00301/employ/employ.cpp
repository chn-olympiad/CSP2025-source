#include<bits/stdc++.h>
#define IO(x) freopen(#x ".in","r",stdin); freopen(#x ".out","w",stdout);
#define MAXN 110000
using namespace std;
int G[MAXN],Book[MAXN],n,m,C[MAXN],A[MAXN],Ans;
string S;
void dfs(int x){
	if(x==n+1){
		int Sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(A[i]==1&&C[G[i]]>cnt)Sum++;
			else cnt++;
		}
		if(Sum>=m)Ans++;
		return;
	}	
	for(int i=1;i<=n;i++){
		if(Book[i])continue;
		Book[i]=1;
		G[x]=i;
		dfs(x+1);
		Book[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> S;
	int len=S.size();
	S=" "+S;
	for(int i=1;i<=len;i++)A[i]=S[i]-'0';
	for(int i=1;i<=n;i++)cin >> C[i];
	dfs(1);
	cout << Ans << endl;
	return 0;
}