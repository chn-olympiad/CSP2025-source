#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[510],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=m;i<=n;i++){
		//int tmp=m;
		for(int j=n;j>=n-i+1;j--){
			ans*=j;
			//ans/=tmp;
			ans%=998244353;
			//tmp--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
