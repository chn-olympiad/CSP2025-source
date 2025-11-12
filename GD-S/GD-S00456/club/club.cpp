#include<bits/stdc++.h>
using namespace std;
int happy_ar[100005][5];
int maxn;
int club_p[4]={};
int n;
void dfs(int person_i,int sum_h){//当前索引的人person_i,未加上本次索引的happy的sum_h 
	//cout<<".........."<<person_i-1<<"......."<<sum_h<<endl; 
	//当最后一个人选择社团时，只需要将自己最喜欢的社团中人数未满的happy值
	if(person_i==n){
		for(int i=1;i<=3;i++){
			if(club_p[i]>n/2)continue;//人数已满 
			//cout<<".........."<<person_i<<"......."<<sum_h+happy_ar[person_i][i]<<endl; 
			maxn=max(maxn,sum_h+happy_ar[person_i][i]);//比较并存储最大值 
		}
		return;
	} 
	for(int i=1;i<=3;i++){//人选择社团 
		if(club_p[i]==n/2)continue;//若人选择的社团人数已经满了，跳过 
		club_p[i]++;//更新这个社团的人数 
		//cout<<club_p[i]<<"*"<<endl;
		dfs(person_i+1,sum_h+happy_ar[person_i][i]);//下一个人进行选择社团 
		club_p[i]--;//还原社团人数 
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>happy_ar[j][1]>>happy_ar[j][2]>>happy_ar[j][3];
		}
		maxn=0;
		dfs(1,0);
		cout<<maxn<<endl;
	}
	return 0;
}
