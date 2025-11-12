#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define int ll
const int mod=998244353;
const int N=1e5+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,m;
string s;
int a[N]={};
int p[N]={};
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IO;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=i;
	}
	int res=0;
	if(n<=10){
		do{
			int cnt=0,ans=0;
			for(int i=1;i<=n;i++){
				if(cnt<a[p[i]]){
					if(s[i-1]=='1'){
						ans++;
					}else{
						cnt++;
					}
				}else{
					cnt++;
				}
			}
			if(ans>=m){
				res=(res+1)%mod;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<res<<endl;
	}
	return 0;
}
