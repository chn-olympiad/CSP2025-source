#include<bits/stdc++.h>
using namespace std;
int a[5010],n;
long long T=0;
void dfs(int maxs,int sum,int x,int usees){
	//cout<<sum<<' '<<maxs<<' '<<usees<<'\n';
	bool f=(usees>=3)&&((maxs*2)<sum);
	if(f) T++;
	//cout<<int(f)<<"aaaaaaa\n";
	if(x>=n) return;
	//if(((maxs*2)>=sum)&&f) return;
	//if(f) T++;
	dfs(max(maxs,a[x+1]),sum+a[x+1],x+1,usees+1);
	dfs(maxs,sum,x+1,usees);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(-1,0,0,0);
	cout<<T-2;
	return 0;
}
