#include<bits/stdc++.h>
#define qwq return
#define zzz long long
using namespace std;
zzz n,a[1000001],ans=0;
void dfs(zzz i,zzz mx,zzz sum,zzz num){
	if(i>n){
//		cout<<mx<<' '<<sum<<" "<<num<<endl;
		if(num>=3&&sum>mx*2){
			ans++;
		}
		qwq;
	}
	dfs(i+1,max(mx,a[i]),sum+a[i],num+1);
	dfs(i+1,mx,sum,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(zzz i=1;i<=n;i++)cin>>a[i];
	dfs(1,INT_MIN,0,0);
	cout<<ans;
	qwq 0;
}