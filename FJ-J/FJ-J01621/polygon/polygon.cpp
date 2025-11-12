#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,f,msd;
int lon[N],ans[N];
bool vis[N];
bool can_polygon(int ans[]){
	int maxed=0,added=0;
	for(int i=1;i<=f;i++){
		maxed=max(maxed,ans[i]);
		added+=ans[i];
	}
	if(maxed*2>=added){
		return false;
	}
	return true;
}
void dfs(int pos,int cnt){
	if(cnt>f){//选到头了 
		if(can_polygon(ans)){
			msd++;
			msd%=998244353;
		}
		return;
	}
	for(int i=pos;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;//选 
			ans[cnt]=lon[i];
			dfs(i+1,cnt+1);//继续选下一个
			vis[i]=0;//回溯：不选 
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lon[i];
	}
	for(f=3;f<=n;f++){
		dfs(1,1);
	}
	cout<<msd;
	return 0;
} 
