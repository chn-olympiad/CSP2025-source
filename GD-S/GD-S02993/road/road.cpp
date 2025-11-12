#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 6000
int mp[Max][Max];
int n,m,k;
int a,b,d;
int k_num,k_data[Max][Max];
int ans[Max],num=0,ok,MIN;
int fd[Max];
void dfs(int now,int ans_ans){
	fd[now]=1;
    for(int i=1;i<=n;i++){
    	if(fd[i]==0&&mp[now][i]!=99999999){
    		ok++,dfs(i,ans_ans+mp[now][i]),ok--; 	
		} 
	}
	if(ok>=n) 
		MIN=min(MIN,ans_ans);
	fd[now]=0;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m>>k;
	MIN=9999999;
	ok=1;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			mp[i][j]=99999999,mp[i][i]=0,ans[i]=9999999;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>d;
		mp[a][b]=d;
		mp[b][a]=d;
	}
	for(int i=1;i<=k;i++){
		cin>>k_num;
		for(int j=1;j<=n;j++){
			cin>>k_data[i][j];	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k;o++)
			mp[i][j]=min(mp[i][j],k_data[o][j]+k_data[o][i]);
		}
	}
	for(int i=0;i<=n+2;i++) fd[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	MIN=9999999;
	dfs(1,0);
	cout<<MIN;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/ 
