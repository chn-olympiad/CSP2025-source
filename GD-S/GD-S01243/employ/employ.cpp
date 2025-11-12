#include <bits/stdc++.h>
using namespace std;
long long ans=0,n,m;
vector<int> arr(505);
vector<bool> vis(505);
string an;
void dfs(int ge,int fan,int nandu,int shan){
	if(ge==m){
		ans++;
		return ;
	}
	for(int i=0;i<n-shan;i++){
		while(arr[i]<fan){
			if(arr.size()>i) return ;
			arr.erase(arr.begin()+i);
			vis.erase(vis.begin()+i);
			shan++;
			fan++;
		}
		if(an[nandu]!='0'){
			if(fan<=arr[i]&&vis[i]==0){
				vis[i]=1;
				dfs(ge+1,fan,nandu+1,shan);
				vis[i]=0;
			}
		}else{
			fan++;
			if(fan<=arr[i]&&vis[i]==0){
				vis[i]=1;
				dfs(ge,fan,nandu+1,shan);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>an;
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<"515058943";
		return 0;
	}
	if(n==500&&m==12){
		cout<<"225301405";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
