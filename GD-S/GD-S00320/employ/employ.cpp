#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=998244353;
int n,m;
int c[N],p[N];
ll ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="#"+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&i-1-cnt<c[p[i]])cnt++;
			if(cnt>=m){
				ans++;
				break;
			}
		}
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
} 
