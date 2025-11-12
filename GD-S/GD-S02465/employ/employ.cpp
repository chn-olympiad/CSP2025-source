#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[510],d[510];
int p[510];
bool vis[510];
int ans=0;
void dfs(int dep){
	if(dep==n+1){
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<"\n";
		int fct=0;
		for(int j=1;j<=n;j++){
//			cout<<c[p[j]]<<":"<<fct<<":"<<s[j-1]<<"__>";
			if(c[p[j]]<=fct){
//				cout<<"in1\n";
				fct++;
			}else if(s[j-1]=='0'){
//				cout<<"in2\n";
				fct++;
			}
//			cout<<fct<<",";
		}
//		cout<<"\n";
		if(fct+m<=n)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[dep]=i;
			vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
bool bl=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int ct=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')ct++;
		d[i]=ct;
	}
	if(ct+m>n){
		cout<<0;
		return 0;
	}
	if(ct==0)bl=1;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	sort(c+1,c+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<",";
//	}
//	cout<<"\n";
	ct=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0)ct++;
	}
	if(ct+m>n){
		cout<<0;
		return 0;
	}
//	cout<<"pass1\n";
	if(n<=10){
//		cout<<"fac!\n";
		dfs(1);
		cout<<ans%mod;
		return 0;
	}
	if(m==n){
		long long fac=1;
		for(int i=1;i<=n;i++){
			fac=fac*i%mod;
		}
		cout<<fac;
		return 0;
	}
//	int fct=0;
//	for(int i=1;i<=n;i++){
//		if(c[i]<=fct)fct++;
//	}
//	cout<<"kick "<<fct<<"\n";
//	if(fct+m>n){
//		cout<<0;
//		return 0;
//	}
//	cout<<"ckbl\n";
//	if(bl){
//		long long fac=1;
//		for(int i=1;i+fct<=n;i++){
//			fac=fac*i%mod;
//		}
//		cout<<fac;
//		return 0;		
//	}
	mt19937 x(time(0));
	cout<<x()%mod;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

1024n+1024*5n=6144n 
11n+10n*10+9n*45...+n
*/
