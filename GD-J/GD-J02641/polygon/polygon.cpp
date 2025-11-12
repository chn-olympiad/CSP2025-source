#include<bits/stdc++.h>
using namespace std;
int n;
int a[500000];
int ans;
void dfs(int pos,int sum,int mx){
	if(pos==n+1){
		//cout<<"-----"<<endl;
		if(sum>2*mx){
			ans++;
			ans%=998244353;
		}
		return;
	}
	//cout<<"Ñ¡Ôñ £º"<<pos<<endl;
	dfs(pos+1,sum+a[pos],max(mx,a[pos]));
	//cout<<"²»Ñ¡Ôñ £º"<<pos<<endl;
	dfs(pos+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}
