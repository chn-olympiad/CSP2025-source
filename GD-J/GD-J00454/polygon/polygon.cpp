#include<bits/stdc++.h>//选出的不相交区间数量的最大值
using namespace std;
const int M=998244353;
int n,ans;
int a[5001];
/*
5
1 2 3 4 5
*/
string s;
map<string,bool>m;
void dfs(long long len,int maxx,int xb,int much){
	//s={len,maxx,xb,much};
	//m[s]=1;
	if(much>=3&&len>(maxx<<1)){
		ans++;
		return ;
	}
	for(int i=xb+1;i<=n;i++){
		maxx=max(maxx,a[i]);
		//s={len,maxx,i,much+1};
		//if(m[s]==1)continue;
		dfs(len+a[i],maxx,i,much+1);
	}
}
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
