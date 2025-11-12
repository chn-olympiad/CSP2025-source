//GZ-S00310 贵阳市第三实验中学 王号东
#include<bits/stdc++.h>
using namespace std;

long long int testt;		//测试数据组数
long long int Detern;		//新成员数量
struct aman{
	long long int ma;		//分别为一个成员对第1,2,3个部门的满意程度 
	long long int mb;
	long long int mc;
}; 
long long int maxnumn;		//一个部门最多可容纳多少个人 
aman Detera[400004];
long long int ans;


void csh(){
	for(int i=1;i<=Detern;i++){
		Detera[i].ma=0;
		Detera[i].mb=0;
		Detera[i].mc=0;
	}
	maxnumn=Detern/2;
	ans=0;
	return;
}

void dfs(long long int seiman,long long int havanow,long long int havbnow,long long int havcnow,long long int ansnow){
//目前搜到了第几个人，第1，2，3组已经有了多少个人 ,目前的满意度 
	if(ansnow>ans){
		ans=ansnow;
	}
	if(seiman>Detern){
		return;
	}
	if(havanow<maxnumn){
		dfs(seiman+1,havanow+1,havbnow,havcnow,ansnow+Detera[seiman].ma);
	}
	if(havbnow<maxnumn){
		dfs(seiman+1,havanow,havbnow+1,havcnow,ansnow+Detera[seiman].mb);
	}
	if(havcnow<maxnumn){
		dfs(seiman+1,havanow,havbnow,havcnow+1,ansnow+Detera[seiman].mc);
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>testt;
	while(testt--){
		cin>>Detern;
		csh();
		for(int i=1;i<=Detern;i++){
			cin>>Detera[i].ma;
			cin>>Detera[i].mb;
			cin>>Detera[i].mc;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
