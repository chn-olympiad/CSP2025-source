#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,prdr;
int a[5005];
void dfs(int x,int k,int num,int las){
	if(x==k){
		if(num>2*a[las]){
			prdr++;
		}
		return ;
	}
	int op=las;
	for(int i=las+1;i<=(n-k+x+1);i++){
		num+=a[i];
		las=i;
		dfs(x+1,k,num,las);
		las=op;
		num-=a[i];
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0);
	}
	cout<<prdr;
	return 0;
// ALove7eno
}
