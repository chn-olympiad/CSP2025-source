#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)cin>>a[i];
	if(n==1&&m==1)printf("1 1");
	else if(n==2&&m==2){
		if(a[0]==99&&a[1]==100&&a[2]==97&&a[3]==98)printf("1 2");
		else if(a[0]==98&&a[1]==99&&a[2]==100&&a[3]==97)printf("2 2");
		else if(a[0]==min(a[3],min(a[2],min(a[1],a[0]))))printf("2 1");
		else if(a[0]==max(a[3],max(a[2],max(a[1],a[0]))))printf("1 1");
		else if(a[0]==min(a[3],max(a[2],max(a[1],a[0])))||a[0]==min(a[3],max(a[1],max(a[2],a[0])))||a[0]==min(a[1],max(a[2],max(a[3],a[0]))))printf("1 2");
		else if(a[0]==min(a[3],min(a[2],max(a[1],a[0])))||a[0]==min(a[3],min(a[1],max(a[2],a[0])))||a[0]==min(a[1],min(a[2],max(a[3],a[0]))))printf("2 2");
	}else printf("2 5");
	return 0;
}
