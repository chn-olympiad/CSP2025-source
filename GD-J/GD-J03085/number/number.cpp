#include<bits/stdc++.h>
using namespace std;
char s[1000005];
long long cnt,shu[1000005],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(long long i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			shu[++cnt]=s[i]-'0';
		}
	}
	sort(shu+1,shu+1+cnt);
	for(long long i=cnt;i>=1;i--){
		printf("%lld",shu[i]);
	}
	return 0;
} 
