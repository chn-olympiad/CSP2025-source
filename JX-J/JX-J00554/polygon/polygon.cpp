#include<bits/stdc++.h>
using namespace std;
int n,j8;
int bj[501];
int aa[501];
int tot;
int maxaa;
long long kkk;
long long nt=1;
void dfs(int a,int xs,int cnt,int maxa){
	if(a==n+1){
		if(xs>=3){
			if(cnt>maxa*2){
				tot++;
			}
		}
		return;
	}
	bj[a]=1;
	dfs(a+1,xs+1,cnt+aa[a],max(maxa,aa[a]));
	bj[a]=0;
	dfs(a+1,xs,cnt,maxa);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
		maxaa=max(maxaa,aa[i]);
	}
	dfs(1,0,0,0);
	cout<<tot;
	return 0;
}
