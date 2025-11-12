#include <bits/stdc++.h>
using namespace std;

int a[5005];

int f(int maxx,int b,long long he){
	if (b<=0){
		if (he>maxx*2)
			return 1;
		else
			return 0;
	}
	else
		return (f(max(a[b],maxx),b-1,he+a[b])+f(maxx,b-1,he))%998244353;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,c=0;
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	cout << f(0,n,0) << endl;
	
	return 0;
}
