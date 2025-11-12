#include<bits/stdc++.h>
using namespace std;
#define maxa 998244353
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,c[1001],ans=0,a[1000],z=0;
	char s[10101];
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>s[i];
	for(int i=1;i<=n;i++)  cin>>c[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
