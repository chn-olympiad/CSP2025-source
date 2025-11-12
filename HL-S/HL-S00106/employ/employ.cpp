#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
string s;
int a[510],b[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int f=0;
	ll j=479001600;//12!
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
		if(a[i+1]==1&&f==0) f=i+1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	if(m==1){
		sort(b+1,b+1+n);
		int x=lower_bound(b+1,b+n+1,f)-b;
		if(b[x]!=f) x--;
		ll ans1=1,ans2=1;
		if(f-1<12){
			for(int i=2;i<=f-1;i++){
				ans1*=i;
			}
			ans1=ans1%998244353;
		}
		else if(f-1==12) ans1=j;
		else{
			for(int i=13;i<=f-1;i++){
				ans1=ans1%998244353*i%998244353;
			}
			ans1=ans1%998244353*j%998244353;
		}
		if(n-f+1<12){
			for(int i=2;i<=n-f+1;i++){
				ans2*=i;
			}
			ans2=ans2%998244353;
		}
		else if(n-f+1==12) ans2=j;
		else{
			for(int i=13;i<=n-f+1;i++){
				ans2=ans2%998244353*i;
			}
			ans2=ans2%998244353*j%998244353;
		}
		ll aans=1;
		aans=ans1*ans2%998244353*x%998244353;
		printf("%lld",aans);
	}
	return 0;
}