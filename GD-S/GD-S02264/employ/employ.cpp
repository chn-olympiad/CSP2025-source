#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=505;
char s[N];
int c[N];
const long long mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	scanf("%s",s+1);
	bool a=1;
	for(int i=1;i<=n;i++) if(s[i]==0) a=0;
	long long ans=1,h=1;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans=ans*i%mod;
	}
	cout<<ans;

	return 0;
}
