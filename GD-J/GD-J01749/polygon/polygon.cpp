#include<bits/stdc++.h>
using namespace std;
int n,ans;
int ccf[5010],num[5010],mx=-114514,vis[5010];
void ccfnmsl(int x,int y){
	if(y==x){
		int fl=0;
		for(int i=1;i<=x;i++)fl+=num[i];
		if(fl>=mx*2)ans++;
	}
	for(int i=y;i<=x;i++){
		if(vis[ccf[i]]==0){
			vis[ccf[i]]=1;
			num[i]=ccf[i];
			mx=max(mx,num[i]);
			vis[ccf[i]]=0;
		}
	}	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ccf[i];
	for(int i=3;i<=n;i++){
		ccfnmsl(i,0);
	}
	cout<<ans;
	return 0;
} 
