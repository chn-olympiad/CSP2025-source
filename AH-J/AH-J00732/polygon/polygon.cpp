#include<iostream>
using namespace std;

int n,cnt,ans,sum,maxn;
int a[1000005];
void dfs(int x,int sum,int maxn,int cnt){
	if(x==n+1){
		if(sum>maxn*2){
			ans++;
		}
		return;
	}
	dfs(x+1,sum+a[x],max(maxn,a[x]),cnt+1);
	dfs(x+1,sum,maxn,cnt);
	return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
