#include<iostream>
using namespace std;
int n,m,c;
string s;
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=2;i<=n;i++) ans*=i;
	for(int i=1;i<=n;i++){
		cin >> c;
		if(c==0) ans-=c*n;
	}
	cout << ans;
	return 0;
}
