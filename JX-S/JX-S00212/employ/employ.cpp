#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int Mod=998244353;
int p[N];
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	int cntd=0;
	for(int i=1;i<=n;i++){
		cntd+=(s[i]=='0');
		cin>>c[i];
		p[i]=i;
	}
	if((n-cntd)<m){
		cout<<"0\n";
		return 0;
	}
	long long ans=0;
	do{
		int cntpass=0;
		int cntfail=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cntfail++;
				continue;
			}
			if(cntfail>=c[p[i]]){
				cntfail++;
				continue;
			}
			cntpass++;
		}
		ans+=(cntpass>=m);
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
}
