#include<bits/stdc++.h>
using namespace std;
int lj[1011][1011]={0};
//1¡Ün¡Ü10^4,1¡Üm¡Ü10^6,0¡Ük¡Ü10£»
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		lj[u][v]=w;
		lj[v][u]=w;
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		int a[int(1e4+1)];
		for(int j=0;j<n;j++){
			cin>>a[j];
			for(int k=0;k<j;k++) lj[a[k]][a[j]]=a[k]+a[j]+c,lj[a[j]][a[k]];
		}
	}
	int re=0;
	vector<int> lt;
	bool l[int(1e4+7)];
	l[1]=true;
	lt.push_back(1);
	while(lt.size()<n){
		int mi=2e9,mii=-1;
		for(int i=1;i<=n;i++){
			if(!l[i]) continue;
			for(int j=0;j<lt.size();j++)
				if(lj[i][j]!=0&&lj[i][j]<mi)
					mi=lj[i][j],mii=j;
		}
		l[mii]=true;
		re+=mi;
		lt.push_back(mii);
	}
	cout<<re<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
