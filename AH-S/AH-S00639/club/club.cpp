#include <bits/stdc++.h>
using namespace std;
int a1,a2,a3,b,ans,x[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			if(a1>=a2)b=a1;
			else b=a2;
			if(a3>=b)b=a3;
			ans=ans+b;
			b=0;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
