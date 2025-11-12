#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans=0,num[10005];
void dfs(int m,int h,int hurt,int last){
	if(hurt<3) return ;
	int cnt=0,maxx=0;
	for(int i=1;i<=m;i++){
		if(num[i]==-1) continue;
		maxx=max(maxx,num[i]);
		cnt+=num[i];
	}
	if(cnt>2*maxx){
    	ans++;
    	ans%=998244353;
    }
	for(int i=last;i<=m;i++){
		if(num[i]==-1) continue;
		int hjk=num[i];
		num[i]=-1;
		dfs(m,h+1,hurt-1,i);
		num[i]=hjk;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) num[i]=a[i];
	dfs(n,0,n,1);
	cout<<ans;
	return 0;
}
