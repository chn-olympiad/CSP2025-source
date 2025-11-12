#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],t1,t2=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	t1=a[1];
	for(int i=1;i<=n;i++) t2+=a[i];
	if(n==3&&t2>2*t1) cout<<"1";
	else cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
