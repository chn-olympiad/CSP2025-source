#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5;
struct peo{
	int lik[3];
}a[maxn+5];

vector<peo> v[3];
int n;

bool cmp(peo a,peo b){
	int popular_a=max(max(a.lik[0],a.lik[1]),a.lik[2]),popular_b=max(max(b.lik[0],b.lik[1]),b.lik[2]);
	int second_a,second_b;
	if(popular_a==a.lik[0]) second_a=max(a.lik[1],a.lik[2]);
	else if(popular_a==a.lik[1]) second_a=max(a.lik[0],a.lik[2]);
	else second_a=max(a.lik[0],a.lik[1]);	 
	if(popular_b==b.lik[0]) second_b=max(b.lik[1],b.lik[2]);
	else if(popular_b==b.lik[1]) second_b=max(b.lik[0],b.lik[2]);
	else second_b=max(b.lik[0],b.lik[1]);
	return (popular_a-second_a)>(popular_b-second_b);
}

void get_ans(){
	int ans=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<v[i].size(); j++){
			ans+=v[i][j].lik[i];
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d%d%d",&a[i].lik[0],&a[i].lik[1],&a[i].lik[2]);
			if(a[i].lik[0]>=a[i].lik[1] && a[i].lik[0]>=a[i].lik[2]) v[0].push_back(a[i]);
			else if(a[i].lik[1]>=a[i].lik[0] && a[i].lik[1]>=a[i].lik[2]) v[1].push_back(a[i]);
			else v[2].push_back(a[i]);
		}
		int popular=max(max(v[0].size(),v[1].size()),v[2].size());
		if(popular<=n/2) get_ans();
		else{
			int which;
			if(popular==v[0].size()) which=0;
			else if(popular==v[1].size()) which=1;
			else which=2;
			sort(v[which].begin(),v[which].end(),cmp);
			for(int i=n/2; i<v[which].size(); i++){
				peo k=v[which][i];
				if(which==0) v[((v[which][i].lik[1]>v[which][i].lik[2])?1:2)].push_back(k);
				else if(which==1) v[((v[which][i].lik[0]>v[which][i].lik[2])?0:2)].push_back(k);
				else v[((v[which][i].lik[0]>v[which][i].lik[1])?0:1)].push_back(k);
				v[which][i]={0,0,0};
			}
			get_ans();
		}
	}
	return 0; //expect: 100 pts
}
