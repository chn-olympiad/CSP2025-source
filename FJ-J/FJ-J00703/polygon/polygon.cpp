#include<bits/stdc++.h>
using namespace std;
struct akcspj{
	int x=0,s=0;
}a[5005];
int n;
long long cnt=0;
bool cmp(akcspj qwer,akcspj asdf){
	return qwer.x<asdf.x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)a[i].s=a[i].x+a[i-1].s;
	for(int i=1;i<=n;i++)cnt+=i;
	cout<<cnt%998244353;
	return 0;
} 
