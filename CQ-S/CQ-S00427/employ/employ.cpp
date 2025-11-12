#include<bits\stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,c[505],ans=1;
	string s;
	cin>>n>>m;long long g=0;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0) g++;
	}
	if(n-g<m){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=n;i>=1;i--){
		ans*=(i%998244353);
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}
