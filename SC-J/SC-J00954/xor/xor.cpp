#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[500005];
int f[500005],ans=0;
void getans(){
	int cnt=0;//区间数量
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=f[i];
	}
	if(tmp&1)return ;
	tmp=0;//区间异或
	int flag=0;//是否在区间中
	for(int i=1;i<=n;i++){
		if(f[i]==2){//单独的一点
			tmp=a[i];
			if(tmp!=k)return ;//区间异或不为k
			cnt++;
		}
		else if(flag==0&&f[i]==0){//未被选中的点
            continue;
		}
		else if(flag==0&&f[i]==1){//区间起点
			flag=1;
			cnt++;
			tmp=a[i];
		}
		else if(flag==1&&f[i]==0){//区间中间
			tmp^=a[i];
		}
		else if(flag==1&&f[i]==1){//区间终点
			tmp^=a[i];
			if(tmp!=k)return ;//区间异或不为k
			flag=0;
			tmp=0;
		}
	}
	ans=max(ans,cnt);
	return ;
}
void dfs(int x){
	if(x>n){
		getans();
		return ;
	}
	f[x]=2;
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
	return ;
}
bool fa=1,fb=1,fc=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fa=0;
		if(a[i]>1)fb=0;
		if(a[i]>255)fc=0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}