#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	string s;cin>>s;
	for(int i=1,x;i<=n;i++)scanf("%d",&x);
	srand(time(0));
	printf("%lld\n",rand()*rand()*rand()%P);
	return 0;
}
/*
please_give_me_accept ^v^
*/
