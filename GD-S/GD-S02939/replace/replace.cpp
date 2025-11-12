#include<bits/stdc++.h>
#define INF 2e18
#define fi first
#define se second
#define endl '\n'
#define int long long
#define mem(x,v) memset(x,v,sizoef x)
using namespace std;
const int N = 2e3+5;
const int P = 10007;

int n,m;
int l[N],hs[N][2],ht[2][N];
string s0,s1,t0,t1;

int qpow(int x,int y){
//	cout<<"Q"<<y<<endl;
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%P;
		x=x*x%P,y>>=1;
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s0>>s1,l[i]=s0.size();
		for(int j=0;j<s0.size();j++)hs[i][0]=(hs[i][0]*26+s0[j]-'a'+1)%P;
		for(int j=0;j<s1.size();j++)hs[i][1]=(hs[i][1]*26+s1[j]-'a'+1)%P;
//		cout<<hs[i][0]<<" "<<hs[i][1]<<endl;
	}
	for(int i=1;i<=m;i++){
//		cout<<"Q:"<<i<<endl;
		cin>>t0>>t1;int ans=0;
		int l0=t0.size(),l1=t1.size();
		t0=' '+t0,t1=' '+t1;
		for(int j=1;j<=l0;j++)ht[0][j]=(ht[0][j-1]*26+t0[j]-'a'+1)%P;
		for(int j=1;j<=l1;j++)ht[1][j]=(ht[1][j-1]*26+t1[j]-'a'+1)%P;
		for(int j=1;j<=n;j++){
			for(int k=1;k+l[j]-1<=l0;k++){
				int r=k+l[j]-1;
//				cout<<j<<" "<<k<<" "<<r<<" "<<ht[0][r]-ht[0][k-1]<<" "<<hs[j][0]*(r-k)<<" "<<ht[1][r]-ht[1][k-1]<<" "<<hs[j][1]*(r-k)<<endl;
				if((ht[0][k-1]*qpow(26,r-k+1)+hs[j][0])%P==ht[0][r]&&(hs[j][1]+ht[1][k-1]*qpow(26,r-k+1))%P==ht[1][r]){
//					cout<<n-r<<endl;
					if(ht[0][k-1]==ht[1][k-1]&&((ht[0][l0]+ht[1][r]*qpow(26,l0-r))%P==(ht[1][l0]+ht[0][r]*qpow(26,l0-r))%P)){
						ans++;
//						cout<<j<<" "<<k<<" "<<r<<endl;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
/*
18:15 1~5 25pts
*/

