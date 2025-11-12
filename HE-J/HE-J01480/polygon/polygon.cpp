#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],s[5005],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	//int l,r;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	/*cin>>l>>r;
	cout<<s[r]-s[l-1];*/
	if (n<3){
		cout<<0;
		return 0;
	}
	if (n<=3){
		int maxn=max(a[1],max(a[2],a[3]));
		if (a[1]+a[2]+a[3]>maxn*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	long long y=n*(n-1);
	cout<<y%998244353;
	return 0;
}
