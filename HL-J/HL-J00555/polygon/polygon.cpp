#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0;
void dfs(int x,int y,int now){
	for(int i=1;i<=n;i++){
		int tmp,tmp1;
		if(y>a[i]) tmp=y;
		else tmp=a[i];
		tmp1=x+a[i];
		if(tmp1>2*tmp||now<2){
			if(now>2) ans++;
			dfs(tmp1,tmp,now+1);
		}
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

