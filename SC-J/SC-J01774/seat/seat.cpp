#include <bits/stdc++.h>
using namespace std;
//freopen(stdin,"r","number.in");
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m+2];
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int a=s[1];
	sort(s,s+0);
	int b;
	for(int i=0;i<=n*m;i++){
		if(s[i]==a) b=i;
		break;
	}
	cout<<b%n<<b/n;
	return 0;
}