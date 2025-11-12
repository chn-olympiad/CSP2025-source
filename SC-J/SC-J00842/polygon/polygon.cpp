#include<bits/stdc++.h>
using namespace std;

const int MAXN=5050,MOD=998244353;
int n;
int s[MAXN],ans=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	sort(s+1,s+1+n,cmp);
	if(n<3){printf("0\n");return 0;}
	if(s[2]+s[3]>s[1]) printf("1\n");
	else printf("0\n");
	return 0;
}