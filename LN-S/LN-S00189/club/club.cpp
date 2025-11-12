#include<bits/stdc++.h>
using namespace std;
struct Node{
	long ren;
	long pos;
	long number;
};
/*
long findMax(long n){
	long l=0,r=1e9,mid;
	while(l<r){
		mid=r-(r-l)/2;
		if(check1(mid,n)) l=mid;
		else r=mid-1;
		//cout<<"mid="<<mid<<" l="<<l<<" r="<<r<<endl;
	}
	return l;
}*/
bool cmp(Node x,Node y){
	return x.number>y.number;
}
long a[100005][4]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long t;
	//cout<<findMax();
	
	cin>>t;
	while(t--){
		long n;
		vector<Node> a;
		//long a1[100001][1],b1,c1;
		cin>>n;
		for(long i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				//cin>>a[i][n];
			//	cin>>a[i][j];
			Node io;
			io.ren=i;
			io.pos=j;
				cin>>io.number;
				a.push_back(io);
			}
		}
		long ans=0;
		sort(a.begin(),a.end(),cmp);
		for(long i=0;i<=n/2-1;i++){
			ans+=a[i].number;
			
		}
		cout<<ans<<endl;
		/*
		long dp[1005][1005]={},t1,t2,t3;
		for(long i=1;i<=n;i++){
			for(long j=1;j<=n;j++){
				if(t1[i][j]==0)
				dp[i][j]=max(max(dp[i-1][j-1]+a[i][1],dp[i-1][j-1]+a[i][2]),dp[i-1][j-1]+a[i][3]);
			}
		}*/
		
	}
}
//Ren5Jie4Di4Ling5%
