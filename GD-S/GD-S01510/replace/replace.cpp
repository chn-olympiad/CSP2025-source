#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
const int N=2e5+10;
string s[N][3];
string qu[N][3];
int ans;
bool find(int id,int u){
	if(s[u][1]==qu[id][1]&&s[u][2]==qu[id][2]) return true;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i][1]>>qu[i][2];
		if(qu[i][1].size()!=qu[i][2].size()){
			printf("0\n");
			continue;
		}
		for(int j=1;j<=n;j++){
			if(find(i,j)) ans++;
		}
		printf("%lld",ans); 
	}
	return 0;
}
