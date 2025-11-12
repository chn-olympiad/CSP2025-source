#include<bits/stdc++.h>
using namespace std;
int t,n,x[3]={0,0,0},cnt[100005]={0};int res=0,x1,x2,x3;
vector<int> val[3];
int max4(int a,int b,int c,int d){
	return max(a,max(b,max(c,d)));
}
void f(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cnt[i]=max4(cnt[i],cnt[i-1]+val[0][j],cnt[i-1]+val[1][j],cnt[i-1]+val[2][j]);
		}
	}
	res=cnt[n];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x1>>x2>>x3;
			val[0].push_back(x1);
			val[1].push_back(x2);
			val[2].push_back(x3);
		}
		cnt[0]=0;
		f();
		cout<<res<<'\n';
		memset(cnt,0,sizeof cnt);
		val[0].resize(0);
		val[1].resize(0);
		val[2].resize(0);
	}
	return 0;
}
