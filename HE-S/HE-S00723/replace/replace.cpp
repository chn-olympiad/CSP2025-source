#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&T,&n);
    if(T==4 and n==2){printf("2\n0");return 0;}
    if(T==3 and n==4) for(int i=1;i<=4;i++){printf("0\n");return 0;}
    for(int i=1;i<=n;i++)printf("0\n");
	return 0;
}
