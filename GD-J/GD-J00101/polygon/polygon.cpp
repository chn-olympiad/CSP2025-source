#include<bits/stdc++.h>
using namespace std;
int n,s[5005],cnt,sum;
int find(int su,int k,int m){
	for(int i=k;i>=1;i--){
		if(su+s[i]>2*m){
			return i;
		}
		else{
			find(su+s[i],i-1,m);
		}
	}
	return 0;
}
void c(int a,int b){
	int ji=1;
	for(int i=b;i>a;i--)ji*=i;
	for(int i=b-a;i>=1;i--)ji/=i;
	cnt+=ji;
	cnt%=998244353;
}
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	sort(s+1,s+n+1);
	for(int i=n;i>=1;i--){
		sum=0;
		int x=find(s[i],i-1,s[i]);
		if(x>=1)cnt++;
		for(int j=x-1;x>=1;x--){
			c(j,x);
		}
	}
	printf("%d",cnt);
	return 0;
}
