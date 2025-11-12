#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[100007];
long long jie;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int len=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0){
			len++;
		}
	}
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			flag=1;
		}
	}
	if(!flag){
		jie=1;
		for(int j=1;j<=len;j++){
			jie=(jie%mod*j%mod)%mod;
		}
		printf("%lld",jie);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
