#include<bits/stdc++.h>
using namespace std;

struct love{
	int a1,a2,a3;
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	int s[t];
	for(int i=0;i<=t-1;i++){
		int n;
		scanf("%d",&n);
		love b[n];
		int maxn=0;
		for(int j=0;j<=n-1;j++){
			scanf("%d %d %d",&b[j].a1,&b[j].a2,&b[j].a3);
			maxn+=max(b[j].a1,b[j].a2,b[j].a3);
		}
		s[i]=maxn;
	}
	for(int i=0;i<=t-1;i++){
		printf("%d\n",s[i]);
	}
	
	return 0;
} 
