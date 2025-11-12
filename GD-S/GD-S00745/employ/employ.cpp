#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int a[505];
long int ans=0;
int p[505];//p【i】表示 第i个应试者是哪位（编号） 
bool flag[505];//是否已经排好 
void dfs(int k,int num,int tao){
	if(k==n){
		if(num>=m) ans++;
		if(ans>=998244353){
			ans%=998244353;
		}
		return; 
	}else{
		if(n-k<m-num){
			return ;
		}
		for(int i=1;i<=n;i++){
			if(flag[i]==false){
				p[k+1]=i;flag[i]=true;
				if(tao<a[i]&&s[k+1]=='1'){
					dfs(k+1,num+1,tao);
				}else{
					dfs(k+1,num,tao+1);
				}
				p[k+1]=0;flag[i]=false;
			}
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool cnt1=true,cnt2=true;//满足m=1时的极端情况 
	bool cnt3=true,cnt4=true;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'&&cnt1)cnt1=false;
		if(s[i]=='0'&&cnt3)cnt3=false;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=false;
		if(a[i]>=1&&cnt2)cnt2=false;
		if(a[i]==0&&cnt4)cnt4=false;
	}
	if(m==1){
		if(cnt1||cnt2) ans=0;
		else dfs(0,0,0);
	}else if(m==n){
		if(cnt3&&cnt4) ans=0;
		else dfs(0,0,0);
	}else{
		dfs(0,0,0);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3 2
//101
//1 1 2
