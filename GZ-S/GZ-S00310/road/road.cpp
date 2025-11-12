//GZ-S00310 贵阳市第三实验中学 王号东
#include<bits/stdc++.h>
using namespace std;


long long int Detern;
long long int Determ;
long long int Deterk;
struct ed{
	int st;		//连接的第一座 
	int en;		//连接的第二座 
	int wea;	//修复花费 
};
int binchaji[20002];
vector<ed>Detera[2000002];
long long int ans;

void csh(){
	for(int i=1;i<=Detern;i++){
		binchaji[i]=i;
	}
	ans=0;
}

int findf(int x){			//返回x的父节点 
	while(binchaji[x]!=x){
		binchaji[x]=binchaji[binchaji[x]];
		x=binchaji[x];
	}
	return binchaji[x];
}

void lianjie(int x,int y){	//合并x,y所在的集合 
	binchaji[findf(x)]=findf(y);
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>Detern>>Determ>>Deterk;
	csh();
	int ca;
	int cb;
	int cc;
	for(int i=1;i<=Determ;i++){
		cin>>ca>>cb>>cc;
		ed Deterl;
		Deterl.st=ca;
		Deterl.en=cb;
		Deterl.wea=cc;
		Detera[i].push_back(Deterl);
	}
	int Deterx;
	int Detery;
	for(int i=1;i<=Deterk;i++){
		cin>>Deterx;
		for(int j=1;j<=Detern;j++){
			cin>>Detery;
			lianjie(Deterx,Detery);
		}
	}
Detergo:
	long long int l=1;
	for(;l<=Detern;l++){
		if(findf(l)!=findf(1)){
			break;
		}
	}
	if(l==Detern+1){
		cout<<ans<<'\n';
		return 0;
	}else{
		long long int myside=1000000008;
		long long int mysidenum=0;
		for(int i=0;i<Detera[l].size();i++){
			if(Detera[l][i].wea<myside){
				myside=Detera[l][i].wea;
				mysidenum=i;
			}
		}
		ans+=myside;
		lianjie(Detera[l][mysidenum].st,Detera[l][mysidenum].en);
		goto Detergo;
	}
}
