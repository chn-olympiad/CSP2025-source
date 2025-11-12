#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=510;
const int p=998244353;
int n,m,s[N],c[N];
bool f=0;
char x;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>x;
		s[i]=x-'0';
		if (s[i]==0)
			f=1;
	}
	for (int i=1;i<=n;i++)
		cin>>c[i];
	if (f==0){
		sort(c+1,c+n+1);
		long long ans=1;
		for (int i=1;i<=n-m;i++){
			ans=ans*(i-c[i])%p;
		}
		ans%=p;
		for (int i=n-m+1;i<=n;i++){
			ans=ans*max(i,c[i])%p;
		}
		cout<<ans;
	}
	return 0;
}
