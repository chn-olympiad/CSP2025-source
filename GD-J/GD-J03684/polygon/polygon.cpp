#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005],cnt[5005];
bool vis[5005];//全排列 
int sum=0,maxx=0,d=0;//和，最大值,方案数

//记忆化 
int f[9999+5][5005] ;//和为i，最大值为j时 
void dfs(int x,int dep){
	if(f[sum][maxx]>0){//已经不行 
		return ;
	}
	if(x>dep){
		if(sum<=2*maxx){//判断条件 
		    f[sum][maxx]+=1;
			return ;
		}
		if(f[sum][maxx]==0){
			d=(d+1)%998244353;
			f[sum][maxx]+=1;
		}
		
		return ;
	}
	int tmp1=sum,tmp2=maxx;//方便回溯 
	for(int i=1;i<=9;i++){
		if(cnt[i]==0||f[sum+i][max(maxx,i)]>0){//不符合跳过
			continue;
		}
		sum+=i;
		maxx=max(maxx,i);
		cnt[i]--;
		
		dfs(x+1,dep);
		sum=tmp1;
		maxx=tmp2;
		cnt[i]++;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	} 
	

	for(int len=3;len<=n;len++){
		dfs(1,len);
		sum=0,maxx=0;//初始化 
	}
	cout<<d;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

//5 1 2 3 4 5
