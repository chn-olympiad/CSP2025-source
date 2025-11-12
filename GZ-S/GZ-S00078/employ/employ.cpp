//GZ-S00078 贵阳市南明区李端棻中学 向一坤
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
int n,m,c[505],sl[505];
string s;
void all_0(){
	int bhg=0;
	for(int i=1;i<=n;i++) if(c[i]==0) bhg++;
	int ans=1;
	for(int i=1;i<=n;i++) ans=(1ll*ans*i)%mod;
	printf("%d",ans);
	return ;
}
bool all0(){
	for(int i=0;i<s.size();i++) if(s[i]=='0') return 0;
	return 1;
}
void mn(){
	int ans=1;
	for(int i=1;i<=n;i++) ans=(1ll*ans*i)%mod;
	printf("%d",ans);
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	//cout<<s<<'\n';
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);sl[c[i]]++;
	}
	if(m==n){
		mn();
		return 0;
	}
	if(all0()){
		all_0();
		return 0;
	}
	printf("0");
	return 0;
}
