#include <bits/stdc++.h>
using namespace std;
bool falg[10005]; 
int n,m,k,ans,cnt,zao[11],zao_lu[11][10005];
struct Node{
	int start,end,money;
}road[100000005];
bool cmp(Node a,Node b){
	return a.money<b.money;
}
bool p(){
	for(int i=1;i<=n;i++){
		if(!falg[i]) return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=m;i++){
		cin>>road[i].start>>road[i].end>>road[i].money;
	}
	for(int i=1;i<=k;i++){
		cin>>zao[i];
		for(int j=1;j<=n;j++){
			cin>>zao_lu[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			int xing_road_money=zao_lu[i][road[j].start]+zao_lu[i][road[j].end]+zao[i];
			road[j].money=min(road[j].money,xing_road_money);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bool flag=false;
			for(int l=1;l<=m;l++){
				if((road[l].end==i&&road[l].start==j)||(road[l].start==i&&road[l].end==j)) flag=true;
			}
			if(!flag){
				cnt++;
				road[cnt].start=i;
				road[cnt].end=j;
				road[cnt].money=2*1e9;
				for(int l=1;l<=k;l++){
					road[cnt].money=min(road[cnt].money,zao_lu[l][i]+zao_lu[l][j]+zao[l]);
				}
			}
		}
	}
	cout<<endl;
	sort(road+1,road+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(p()){
			cout<<ans;
			break;
		}
		if(!falg[road[i].end]||!falg[road[i].start]){
			falg[road[i].end]=true;
			falg[road[i].start]=true;
			ans+=road[i].money;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
