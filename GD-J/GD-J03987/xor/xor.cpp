#include<bits/stdc++.h>
using namespace std;
int dp[500010];
int dp2[500010];
int num[500010];
bool p[500010];
int yih(int x,int y){
	if(y>x)swap(x,y);
	int tmp=x^y;
	return tmp;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		dp[i]=dp[i-1]^num[i];
		for(int j=i;j>=1;j--){
			if(p[j])break;
			if((yih(i,j)==k&&i!=j)||num[i]==k){
				p[i]=true;
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
