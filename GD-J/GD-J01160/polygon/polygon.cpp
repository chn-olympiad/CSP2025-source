#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s[5005],t;
void f(long long i,long long l,long long k,long long maxx)
{
	if(k>=3){
		if(maxx*2<l)t++;
	}
	if(i>=n)return;
	if(i<=n-2)
	f(i+2,l+a[i+2],k+1,a[i+2]);
	f(i+1,l+a[i+1],k+1,a[i+1]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f(1,0,0,0);
	f(1,a[1],1,a[1]);
	cout<<t;
	return 0;
} 
