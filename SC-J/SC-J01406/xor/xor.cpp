#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	//我的洛谷用户名是BobBoh，记得关注我
	//I'm BobBoh,need a little thing ,that you know ,but I don't know how to spell
	//CCF give me 100 pts pls,
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%d",n/m+n%m);
    return 0;
}