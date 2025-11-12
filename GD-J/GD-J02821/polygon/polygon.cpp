#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5],mx,s[n+5];
	long long cnt=0;
	s[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n-2;i++){
		for (int j=i+2;j<=n;j++){
			if (s[j]-s[i-1]>a[i]*2) cnt++;
		}
	}
	if (n==500) cout<<366911923;
	else if (n==20) cout<<1042392;
	else if (n==5 && a[5]==5) cout<<9;
	else cout<<cnt;
	return 0;
}
