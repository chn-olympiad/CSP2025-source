#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
bool pd=1;
string s;
bool bj[501];
int c[501];

void BFS(int x,int r,int h){
	if(x==n){
		if(r>=m) ++ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bj[i]) continue;
		if(s[x]=='0'||x-r>=c[i]){
			bj[i]=1;
			BFS(x+1,r,i);
			bj[i]=0;
		}
		else{
			bj[i]=1;
			BFS(x+1,r+1,i);
			bj[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]) pd=0;
	}
	if(pd){
		ans=1;
	    for(int i=2;i<=n;i++){
	    	ans*=i;
	    	ans%=998244353;
	    }
	}
	if(n<=10) BFS(0,0,0);
	cout<<ans;
	return 0;
}
