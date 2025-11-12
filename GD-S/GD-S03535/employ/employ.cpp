#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int md=998244353;
int n,m,c[505],ans=1,jc,A=1,s0s;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') A=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(m==1){
		int j=n+1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				j=i;
				break;
			}
		}
		jc=1;
		if(j==n+1){
			jc=0;
		}
		for(int i=2;i<=(n-j);i++){
			jc*=i;
			jc%=md;
		}
		int di=0;
		for(int i=1;i<=n;i++){
			di++;
			if(c[i]>=j){
				int kk=1;
				for(int l=1;l<=di;l++){
					kk*=jc;
					kk%=md;
				}
				ans+=kk;
				ans%=md;
			}
		}
		if(j==n+1) ans=0;
		printf("%d",ans);
	}
	else if(A==1){
		int jc=1;
		for(int i=n;i>=(m);i--){
			jc*=i;
			jc%=md;
		}
		printf("%d",jc%md);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
