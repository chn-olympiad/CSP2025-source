#include<bits/stdc++.h>

using namespace std;
int n,k;
bool ss[200003],vis[200003];
int main(void){
	//freopen
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>ss[i];
	}
	int cnt=0;
	for(int i=2;i<=n;++i){
		if(vis[i])continue;
		if(ss[i]!=ss[i+1]&&vis[i+1]==0){
			cnt++;
			vis[i]=1;vis[i+1]=1;
		}
	}
	for(int i=2;i<=n;++i){
		if(vis[i])continue;
		if(ss[i]^ss[i-1]^ss[i-2]&&vis[i-1]+vis[i]+vis[i+1]==0&&i>2){
			cnt++;
			vis[i-1]=1;vis[i]=1;vis[i-2]=1;
		}
	}
	cout<<cnt<<endl;
}//#1-5,13,pian30pts.biegua
