#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=205,M=1e5+5;
//bool st;
int T,n,a[M][4],f[N][N][N];
pair<int,int>t[M];
//bool ed;
bool cmp(const pair<int,int>x,const pair<int,int>y){
	return max(x.first,x.second)>max(y.first,y.second);
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
		t[i]={a[i][2]-a[i][1],a[i][3]-a[i][1]};
	} 
	int res=0,mx=-1e9;
	for(int i=1;i<=n;i++)res+=a[i][1];
	memset(f,128,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){
			for(int k=0;k<=min(i,n/2);k++){
				f[i][j][k]=f[i-1][j][k];
				if(j)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+t[i].first);
				if(k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+t[i].second);
			}
		}
	}
	for(int i=0;i<=n/2;i++)for(int j=0;j<=n/2;j++)if(n-i-j<=n/2)mx=max(mx,f[n][i][j]);
	cout<<res+mx<<'\n';
}
void solve2(){
	bool all3=1,all23=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j],all3&=(a[i][3]==0),all23&=(a[i][3]==0&&a[i][2]==0);
		t[i]={a[i][2]-a[i][1],a[i][3]-a[i][1]};
	} 
	int res=0;
	for(int i=1;i<=n;i++)res+=a[i][1];
	sort(t+1,t+1+n,cmp);
	if(all23){
		for(int i=1;i<=n/2;i++)res+=t[i].first;
		cout<<res<<'\n';
	}else {
		for(int i=1;i<=n/2;i++){
			res+=t[i].first;	
		}
		cout<<res<<'\n';
	}
}
void solve4(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
		t[i]={a[i][2]-a[i][1],a[i][3]-a[i][1]};
	} 
	int res=0;
	for(int i=1;i<=n;i++)res+=a[i][1];
	sort(t+1,t+1+n,cmp);
	vector<pair<int,int>>t2,t3;
	for(int i=1;i<=n/2;i++){
		if(t[i].first>t[i].second&&t2.size()<n/2){
			t2.push_back(t[i]),res+=t[i].first;
		}else t3.push_back(t[i]),res+=t[i].second;
	}
	for(int i=n/2+1;i<=n;i++){
		if(max(t[i].first,t[i].second)<0)break;
		if(t[i].first>t[i].second&&t2.size()<n/2){
			t2.push_back(t[i]),res+=t[i].first;
		}else t3.push_back(t[i]),res+=t[i].second;
	}
	cout<<res<<'\n';
}
#undef int 
int main(){
#define int long long 
	ios::sync_with_stdio(0),cin.tie(0);
//	cerr<<(&ed-&st)/1024.0/1024.0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T;T--){
		cin>>n;
		if(n<=200)solve1();
		else solve4();
	}
	
	
	return 0;
} 
