#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n;
	scanf("%d%d",&t,&n);
	for(int i=1;i<=t;i++){
		for(int i=1;i<=n;i++){
			n=i+1,i+2,i+3;
			break;
		}
		printf("%d%d",&t,&n);
}
	return 0;
}
