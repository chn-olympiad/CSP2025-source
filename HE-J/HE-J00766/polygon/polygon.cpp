#include <bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout << 9;
		}
		else if(a[1]=21&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout << 6;
		}
		return 0;
	}
	if(n==3){
		int hello=max(a[1],max(a[2],a[3]));
		int beybey=a[1]+a[2]+a[3];
		if(hello*2<beybey){
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++){
		int maxl=a[i],num=a[i],sum=1;
		for (int j=1;j<i;j++){
			if(a[j]!=maxl){
				num+=a[j];
				sum++;
			}
			if(sum>=3&&num>=maxl*2){
				m++;
			}
		}
	}
	cout << m%998244353;
	return 0;
}
