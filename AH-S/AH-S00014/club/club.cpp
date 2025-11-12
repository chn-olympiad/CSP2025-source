#include<bits/stdc++.h>
using namespace std;

int T;

int n;

int r[1111660][3];

struct node{
	int shu;
	int a;
	int b;
};

int as=0,bs=0,cs=0;

long long maxn=0;

bool especial_A=true;

bool especial_B=true;

bool cmp(node a,node b){
	return a.shu>b.shu;
}

node al[1111660];
long long sum=0;

void dfs(int ndx,long long sum){
	if(ndx==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(as<n/2){
		as++;
		dfs(ndx+1,sum+r[ndx][0]);
		as--;
	}
	if(bs<n/2){
		bs++;
		dfs(ndx+1,sum+r[ndx][1]);
		bs--;
	}
	if(cs<n/2){
		cs++;
		dfs(ndx+1,sum+r[ndx][2]);
		cs--;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		as=bs=cs=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i][0]>>r[i][1]>>r[i][2];
			if(r[i][1]||r[i][2]){
				especial_A=false;
			}
			if(r[i][2]){
				especial_B=false;
			}
		}
		if(especial_A){
			for(int i=1;i<=n;i++){
				al[i].shu=r[i][0];
			}
			sort(al+1,al+1+n,cmp);
			for(int i=n;i>n/2;i--){
				sum+=al[i].shu;
			}
			cout<<sum;
			return 0;
		}
		if(especial_B){
			for(int i=1;i<=n;i++){
				al[i].shu=r[i][0]-r[i][1];
				al[i].a=r[i][0];
				al[i].b=r[i][1];
			}
			sort(al+1,al+1+n,cmp);
			for(int i=n;i>n/2;i--){
				sum+=al[i].a;
			}
			for(int i=n/2;i>=1;i--){
				sum+=al[i].b;
			}
			cout<<sum;
			return 0;
		}
		dfs(1,0);
		cout<<maxn<<endl;
		maxn=0;
	}
}
