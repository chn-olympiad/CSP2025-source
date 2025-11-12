#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int b=0,d=0,ans=0;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			b++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>b)d++;
	}
	if(d>=m){
		ans=n;
		for(int i=n-1;i>=1;i--){
			ans=ans*i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
