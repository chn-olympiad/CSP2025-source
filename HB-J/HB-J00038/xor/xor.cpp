#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	srand(n*k);
	printf("%d",rand()%n+1);
	//du shang wo shi nian yang shou
	//qian cheng bai san bai
	//CCF NB!
	return 0;
}

