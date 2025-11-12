#include<bits/stdc++.h>
using namespace std;

int n;
int a[50000];
int cnt=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	{
		cin>>a[i];
		cnt+=a[i];
	}
	sort(a+1,a+n+1);
	if(cnt>a[n]*2)	cout<<1;
	else cout<<0;
	return 0;
}
