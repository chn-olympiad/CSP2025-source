//GZ-S00195 安顺市第一高级中学 徐陈乾康 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<vector>
using namespace std;
#define ll long long
#define rt return
const ll INF=0x7fffffff;
const ll MAXN=1e8+7;

int u[MAXN],v[MAXN],w[MAXN];
long a[1000007][15];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	ll value=0;
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		value+=w[i];
	}
	
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			cin>>a[j][i];
		}
	}
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			if(w[i]>=a[j][i]) value-=w[i];
			value+=a[j][i];
		}
	}
	
	cout<<value;
	
	fclose(stdin);
	fclose(stdout);
	rt 0;
}
//dlc123 is a Neko
//You can find the name in title at LuoGu
//CCF,it's my second time to play CSP
//This way it's hard to get the good mark
//And this is my last fighting in my middle-school
//Could you please give me some tps? 
//Thanks,CCF...
