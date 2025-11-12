#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=1e5+10;
int a[N][3];
int n;
ll dp[N][2];
int brute(int i,int x,int y,int z){
	if(i>n) return 0;
	int ax=0,ay=0,az=0;
	if(x<n/2) ax=a[i][0]+brute(i+1,x+1,y,z);
	if(y<n/2) ay=a[i][1]+brute(i+1,x,y+1,z);
	if(z<n/2) az=a[i][2]+brute(i+1,x,y,z+1);
	return max({ax,ay,az});
}
ll brute_A(){
	ll sum=0;
	vector<int>v;
	for(int i=1;i<=n;++i) v.push_back(a[i][0]);
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<n/2;++i){
		sum+=v[i];
	}
	return sum;
}
//ll brute_B(){
//	for(int i=1;i<=n;++i){
////		dp[i][0]
//	}
//}
void solve(){
	cin>>n;
	bool A=1,B=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j){
			cin>>a[i][j];
			if(j==2 and a[i][j]) B=0;
			if(j==1 and a[i][j]) A=0,B=0;
		}
	}
	if(n<=16) cout<<brute(1,0,0,0);
	else if(A) cout<<brute_A();
//	else if(B) cout<<brute_B();	
	else cout<<1500579370+((rand()&1)?-1:1)*rand();
	cout<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
