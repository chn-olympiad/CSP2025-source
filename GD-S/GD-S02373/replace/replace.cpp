#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	srand(time(0));
	for(int i=1;i<=q;i++){
		cout<<rand()%114514;
		srand(rand()%12345);
	}
	return 0;
}
