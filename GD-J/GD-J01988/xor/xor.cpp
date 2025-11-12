#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int a[MAXN],s[MAXN],k;
int n;
struct Data{
	int num,last;
}dp[MAXN];
void fast_read(int &f){
	f=0;
	int op=1;
	char c;
	do{
		c=getchar();
		if(c=='-')op=-1;
	}while(!(c>='0'&&c<='9'));
	while(c>='0'&&c<='9')f=f*10+c-'0',c=getchar();
	f=f*op;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	fast_read(n),fast_read(k);
	for(int i=1;i<=n;i++){
		fast_read(a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i].num=dp[i-1].num;
		int l=dp[i-1].last;
		dp[i].last=dp[i-1].last;
		for(int j=l+1;j<=i;j++){
			if((s[i]^s[j-1])==k){
				dp[i].num++;
				dp[i].last=i;
				break;
			}
		}
	}
	printf("%d",dp[n].num);
}
