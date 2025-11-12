#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sumn[500010],dp[500010],q[500010];
int turn(int num,int p){
	if(num==0){
		return 0;
	}
	return turn(num/p,p)*(20/p)+num%p;
}
int Xor(int a1,int b1){
	int x1=turn(a1,2),x2=turn(b1,2);
	string s="";
	while(x1!=0&&x2!=0){
		if(x1%10==x2%10){
			s+='0';
		}else{
			s+='1';
		}
		x1/=10,x2/=10;
	}
	int x=x1+x2;
	for(int i=s.length()-1;i>=0;i--){
		x=x*10+s[i]-'0';
	}
	return turn(x,10);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sumn[i]=Xor(a[i],sumn[i-1]);
	}
	memset(q,-1,sizeof(q));
	for(int i=n;i>=1;i--){
		int num=Xor(sumn[i],k);
		for(int j=i;j>=0;j--){
			if(sumn[j]==num){
				q[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(q[i]!=-1){
			dp[i]=max(dp[i-1],dp[q[i]]+1);
		}else{
			dp[i]=dp[i-1];
		}
	}
	printf("%d",dp[n]);
	return 0;
}
