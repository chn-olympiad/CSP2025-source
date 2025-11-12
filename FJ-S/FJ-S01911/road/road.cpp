#include<bits/stdc++.h>
using namespace std;

long long ans,a[10050][10050],minc=(1<<30)-1;
vector<int> mp[10050];
int n,m,k;
int mina,minb;
bool isq[10050];
vector<int> q;

void sol(){
	q.push_back(mina);
	q.push_back(minb);
	isq[mina]=1;
	isq[minb]=1;
	ans+=minc;
	int tplen=2;
	for(int i=1;i<=n-2;++i){
		minc=-1+(1<<30);
		
		for(int j=0;j<tplen;++j){
			for(int kk=1;kk<=n;++kk){
				if(!isq[kk]&&a[q[j]][kk]!=-1&&minc>a[q[j]][kk]){
					minc=a[q[j]][kk];
					mina=kk;
				}
			}
		}
		ans+=minc;
		isq[mina]=1;
		tplen++;
		q.push_back(mina);
	}
	return;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;++i){
		int tpu,tpv,tpw;
		cin>>tpu>>tpv>>tpw;
		a[tpu][tpv]=tpw;
		a[tpv][tpu]=tpw;
		if(minc>tpw){
			minc=tpw;
			mina=tpu;
			minb=tpv;
		}
	}
	long long tmp;
	for(int i=1;i<=k;++i){
		cin>>tmp;
		for(int j=1;j<=n;++j){
			cin>>tmp;
		}
	}
	
	sol();
	cout<<ans;
	return 0;
}

