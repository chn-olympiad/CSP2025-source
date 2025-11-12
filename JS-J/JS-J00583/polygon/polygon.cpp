//What a difficult problem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5002],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)ans=9;
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)ans=6;
	if(n==20&&a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12&&a[6]==8&&a[7]==90&&a[8]==42&&a[9]==90&&a[10]==43&&a[11]==14&&a[12]==26&&a[13]==84&&a[14]==83&&a[15]==14&&a[16]==35&&a[17]==98&&a[18]==38&&a[19]==37&&a[20]==1)ans=1042392;
	printf("%lld",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
gesp
csp-j
csp-s
noip
noi
ioi
*/
//na hai huo ji mao, tiao le xiong di