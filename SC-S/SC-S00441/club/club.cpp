#include<bits/stdc++.h>
using namespace std;

#define int long long
int read(){
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+(c&15);
		c=getchar();
	}
	return s*f;
}

const int N=1e5+5;

int n;
int a[N][3];
vector<int>v[3];

bool cmp(int x,int y){
	return a[x][2]-a[x][1]>a[y][2]-a[y][1];
}

void Solve(){
	n=read();
	for(int i=0;i<3;i++)v[i].clear();
	for(int i=1;i<=n;i++){
		int mx=-1,mxj;
		for(int j=0;j<3;j++){
			a[i][j]=read();
			if(a[i][j]>mx)mx=a[i][j],mxj=j;
		}
		sort(a[i],a[i]+3);
		v[mxj].emplace_back(i);
	}
	int ans=0;
	for(int i=0;i<3;i++){
		for(int j:v[i])ans+=a[j][2];
		if(v[i].size()>n/2){
			sort(v[i].begin(),v[i].end(),cmp);
			for(int j=n/2;j<v[i].size();j++){
				int p=v[i][j];
				ans+=a[p][1]-a[p][2];
			}
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T=read();
	while(T--)Solve();
	
	return 0;
}