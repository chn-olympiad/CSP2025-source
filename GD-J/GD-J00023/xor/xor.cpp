#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans;
bool v[N];
void bj(int st,int ed){
	for(int i=st;i<=ed;i++) v[i]=1;
}
void dfs(int st,int ed,int res){
	if(res==k){
		ans++;
		bj(st,ed);
//		cout<<st<<" "<<ed<<endl;
		return;
	}
	for(int i=ed+1;i<=n;i++){
		if(i<=n&&!v[st]){
			dfs(st,i,res^a[i]);
		}
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	
//	printf("%d %d\n",n,k);
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);
//	printf("\n");

	for(int i=1;i<=n;i++){
		if(!v[i]) dfs(i,i,a[i]);
	}
	cout<<ans;
	return 0;
}

