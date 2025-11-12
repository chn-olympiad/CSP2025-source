#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5e3+10;
int n,a[maxn];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<3) cout<<0;
	else if(n==3){
		if(a[1]+a[2]<=a[3]) cout<<"0";
		else cout<<"1";
	}
	return 0;
}
