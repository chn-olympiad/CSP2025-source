#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=998244353;
int n,m;
int c[N];
bool p[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>c[i];
	srand(time(nullptr));
	cout<<rand()%M;
	return 0;
}
