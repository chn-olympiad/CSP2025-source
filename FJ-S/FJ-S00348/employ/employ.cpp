#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int s[505];
int c=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,flag=1,flag1=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		if(s[i]==0){
			c++;
			flag=0;
		}
		if(s[i]==1){
			flag1=0;
		}
	}
	if(c>n-m){
		printf("0");
	}
	if(flag1==1||(m==n&&flag==0)){
		printf("0");
		return 0;
	}
	int ans=1;
	if(flag==1||m==1){
		for(int i=2;i<=n;i++){
			ans=(ans*i)%Mod;
		}
		printf("%d",ans);
		return 0;
	}
	printf("0");
	return 0;
}