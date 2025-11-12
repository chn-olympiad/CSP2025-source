#include<bits/stdc++.h>
using namespace std;
int n,m[12],c[1002];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1,cmp);
	if(c[1]+c[2]>c[3])
	printf("%d",1);
	else printf("%d",0);
	return 0;
}
