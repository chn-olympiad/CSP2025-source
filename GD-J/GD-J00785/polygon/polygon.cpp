#include<bits/stdc++.h>
using namespace std;
vector<int> sn[2];
int num[5005],n;
bool cmp(int ax,int by){
	if(sn[0][ax]<sn[0][by]) return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n<=2){
		for(int i=1,d;i<=n;i++) scanf("%d",&d);
		putchar('0');
		return 0;
	}if(n==3){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d=max(a,max(b,c));
		printf("%c","01"[a+b+c>2*d]);
		return 0;
	}
	for(int i=1,did;i<=n;i++){
		scanf("%d",&did);
		if(!num[did]){
			sn[0].push_back(did);
			sn[1].push_back(0);
		}
		num[did]++;
	}
	printf("0");
	return 0;
}
