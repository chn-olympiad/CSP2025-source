#include<bits/stdc++.h>
using namespace std;;
int N,M,Hs=0,Es=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string S;
	scanf("%d%d",&N,&M);
	scanf("%s",&S);
	for(int i=0;i<S.size();i++)
	{
		if (S[i]=='1')
			Es++;
		if (S[i]=='0')
			Hs++;
	}
	if (Hs>M)
	{
		printf("0");
		return 0;
	}
	long long P=1;
	for(int i=1;i<=S.size();i++)
		P=P*(i%998244353)%998244353;
	printf("%lld",P);
	return 0;
}
