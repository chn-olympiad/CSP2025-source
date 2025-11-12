#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
priority_queue<int,vector<int>,greater<int> > a;
priority_queue<int> b;
int n;
struct node{
	//int fir,sed;
	int j1,j2,j3;
}p[N];
bool cmp(node x,node y){
	if(x.j1==y.j1){
		if(x.j2==y.j2){
			return x.j3>y.j3;
		}
		else return x.j2>y.j2;
	}
	else return x.j1>y.j1;
}
int dp[202][102][102][102],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			p[i].j1=x,p[i].j2=y,p[i].j3=z;
			/*
			b.push(x),b.push(y),b.push(z);
			p[i].fir=b.top();
			b.pop();
			p[i].sed=b.top();
			b.pop(),b.pop();
			* */
		}
		if(n>=1000){
			long long ans1=0;
			for(int i=1;i<=n;i++) ans1 += max(p[i].j1,max(p[i].j2,p[i].j3));
			cout<<ans1<<endl;
			continue;
		}
		dp[1][1][0][0]=p[1].j1;
		dp[1][0][1][0]=p[1].j2;
		dp[1][0][0][1]=p[1].j3;
		//sort(p+1,p+n+1,cmp);
		for(int i=2;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
						int maxn=0;
						int w=i-j-k;
						if(w>n/2) continue;
						if(j>0)maxn=dp[i-1][j-1][k][w]+p[i].j1;
						if(k>0)maxn=max(maxn,dp[i-1][j][k-1][w]+p[i].j2);
						if(w>0)maxn=max(maxn,dp[i-1][j][k][w-1]+p[i].j3);
						//cout<<"check"<<j<<" "<<k<<" "<<w<<endl;
						dp[i][j][k][w]=maxn;
						ans=max(ans,maxn);
						//cout<<"step.ans"<<ans<<endl;
			}
		}
			//cout<<p[i].fir<<" "<<p[i].sed<<endl;
	}
	cout<<ans<<endl;
}
	return 0;
}
//Ren5Jie4Di4Ling5%
