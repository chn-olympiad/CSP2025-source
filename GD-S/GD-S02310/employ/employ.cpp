#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,c[20],a[20];
char s[20];
bool check(){
	int cnt=0,fl=0;
	for(int i=1;i<=n;i++){
		if(c[a[i]]<=fl){
			fl++;
			continue;
		}
		if(s[i]=='0')fl++;
		else cnt++;
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)a[i]=i;
	ll ans=0;
	do{
		if(check())ans=(ans+1)%998244353;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
