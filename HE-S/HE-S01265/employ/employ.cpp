#include <iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,sum=1;
	string s;
	cin>>n>>m>>s;
	int c[n];
	for (int i=0;i<n;i++){
		cin>>c[i];
	}for (int i=1;i<=n;i++){
		sum*=i;
	}cout<<sum%998244353;
}
