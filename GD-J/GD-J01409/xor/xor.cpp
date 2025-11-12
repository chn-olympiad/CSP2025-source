#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],ans;
void f1()
{
	if(a[1]==k) ans++;
	if(a[2]==k) ans++;
	if(a[1]^a[2]==k) ans++;
	ans=ans*2;
}
void f2()
{
	int x=0;
	for(int i=1;i<=n;i++) {
		x=a[i];
		if(x==k) ans++;
		for(int j=i+1;j<=n;j++) {
			x=x^a[j];
			if(x==k) ans++;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=2) f1();
	else f2();
	cout<<ans/2;
	return 0;
}
