#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[5050];
int b[5050][5050];
int c[5050][5050];
int n;
ll pd(){
	ll ans=0;
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i][i]=a[i];
		c[i][i]=a[i];
		b[1][i]=b[1][i-1]+a[i];
		c[1][i]=max(c[1][i-1],a[i]);
	}
	if(n<=3){
		if(b[1][3]>c[1][3]*2 && n == 3)
			cout << "1";
		else cout << "0";
	}
	else{
		ll ans=pd();
	}
	return 0;
}
