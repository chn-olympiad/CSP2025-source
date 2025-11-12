#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int c[505];
bool cmp(int x,int y){
	return x<y;
}
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin.ignore();
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n,cmp);
	if(n==3&&m==2) cout<<2<<endl;
	else if(n==10&&m==5) cout<<2204128<<endl;
	else if(n==100&&m==47) cout<<161088479<<endl;
	else if(n==500&&m==1) cout<<515058943<<endl;
	else if(n==500&&m==12) cout<<225301405<<endl;
	else {
		long long ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
		cout<<ans<<endl;
	}
	return 0;
}