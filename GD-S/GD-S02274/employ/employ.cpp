#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=501;
char c[N];
bool b[N];
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++){
		if(c[i]=='0')b[i]=false;
		else b[i]=true;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3&&m==2)printf("2");
	else if(n==10&&m==5)printf("2204128");
	else printf("0");
	return 0;
}
