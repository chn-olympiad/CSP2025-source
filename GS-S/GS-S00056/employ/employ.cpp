#include<bits/stdc++.h>
using namespace std;
int n,m,a[510];
char s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>s[i];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int x=998244353;
	long long nn=1,mm=1;
	for(int i=1;i<=n;i++)
		nn=nn*i;
	for(int i=1;i<=n-m;i++)
		mm=mm*i;
	long long ans=(nn/mm)%x;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
