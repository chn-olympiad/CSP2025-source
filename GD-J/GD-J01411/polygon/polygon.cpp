#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5005;
int n;
int s[MAXN];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1);
	if(n==3){
		if(s[3]<s[2]+s[1])
			printf("1");
		else
			printf("0");
	}else if(n==4){
		int cnt=0;
		if(s[4]<s[1]+s[2])cnt++;
		if(s[4]<s[1]+s[3])cnt++;
		if(s[4]<s[2]+s[3])cnt++;
		if(s[3]<s[1]+s[2])cnt++;
		if(s[4]<s[1]+s[2]+s[3])cnt++;
		printf("%lld",cnt);
	}else if(n==5){
		int cnt=0;
		if(s[3]<s[1]+s[2])cnt++;
		if(s[4]<s[1]+s[2])cnt++;
		if(s[4]<s[1]+s[3])cnt++;
		if(s[4]<s[2]+s[3])cnt++;
		if(s[5]<s[1]+s[2])cnt++;
		if(s[5]<s[1]+s[3])cnt++;
		if(s[5]<s[1]+s[4])cnt++;
		if(s[5]<s[2]+s[3])cnt++;
		if(s[5]<s[2]+s[4])cnt++;
		if(s[5]<s[3]+s[4])cnt++;
		if(s[4]<s[1]+s[2]+s[3])cnt++;
		if(s[5]<s[1]+s[2]+s[3])cnt++;
		if(s[5]<s[1]+s[2]+s[4])cnt++;
		if(s[5]<s[1]+s[3]+s[4])cnt++;
		if(s[5]<s[2]+s[3]+s[4])cnt++;
		if(s[5]<s[1]+s[2]+s[3]+s[4])cnt++;
		printf("%lld",cnt);
	}else if(n==6){
		int cnt=0;
		if(s[3]<s[1]+s[2])cnt++;
		
		if(s[4]<s[1]+s[2])cnt++;
		if(s[4]<s[1]+s[3])cnt++;
		if(s[4]<s[2]+s[3])cnt++;
		
		if(s[5]<s[1]+s[2])cnt++;
		if(s[5]<s[1]+s[3])cnt++;
		if(s[5]<s[1]+s[4])cnt++;
		if(s[5]<s[2]+s[3])cnt++;
		if(s[5]<s[2]+s[4])cnt++;
		if(s[5]<s[3]+s[4])cnt++;
		
		if(s[6]<s[1]+s[2])cnt++;
		if(s[6]<s[1]+s[3])cnt++;
		if(s[6]<s[1]+s[4])cnt++;
		if(s[6]<s[1]+s[5])cnt++;
		if(s[6]<s[2]+s[3])cnt++;
		if(s[6]<s[2]+s[4])cnt++;
		if(s[6]<s[2]+s[5])cnt++;
		if(s[6]<s[3]+s[4])cnt++;
		if(s[6]<s[3]+s[5])cnt++;
		if(s[6]<s[4]+s[5])cnt++;
		
		if(s[4]<s[1]+s[2]+s[3])cnt++;
		
		if(s[5]<s[1]+s[2]+s[3])cnt++;
		if(s[5]<s[1]+s[2]+s[4])cnt++;
		if(s[5]<s[1]+s[3]+s[4])cnt++;
		if(s[5]<s[2]+s[3]+s[4])cnt++;
		
		if(s[6]<s[1]+s[2]+s[3])cnt++;
		if(s[6]<s[1]+s[2]+s[4])cnt++;
		if(s[6]<s[1]+s[2]+s[5])cnt++;
		if(s[6]<s[1]+s[3]+s[4])cnt++;
		if(s[6]<s[1]+s[3]+s[5])cnt++;
		if(s[6]<s[1]+s[4]+s[5])cnt++;
		if(s[6]<s[2]+s[3]+s[4])cnt++;
		if(s[6]<s[2]+s[3]+s[5])cnt++;
		if(s[6]<s[2]+s[4]+s[5])cnt++;
		if(s[6]<s[3]+s[4]+s[5])cnt++;
		
		if(s[5]<s[1]+s[2]+s[3]+s[4])cnt++;
		if(s[6]<s[1]+s[2]+s[3]+s[4])cnt++;
		if(s[6]<s[1]+s[2]+s[3]+s[5])cnt++;
		if(s[6]<s[1]+s[2]+s[4]+s[5])cnt++;
		if(s[6]<s[1]+s[3]+s[4]+s[5])cnt++;
		if(s[6]<s[2]+s[3]+s[4]+s[5])cnt++;
		
		if(s[6]<s[1]+s[2]+s[3]+s[4]+s[5])cnt++;
		printf("%lld",cnt);
	}
	return 0;
}
