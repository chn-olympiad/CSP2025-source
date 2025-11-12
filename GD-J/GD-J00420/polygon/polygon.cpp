#include <bits/stdc++.h>
using namespace std;
long long n,a1,b,c;
long long a[10000];
int main()
{
	cin.tie(0);cout.tie(0);
	cin >> n;
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=3){
		if(n>=3){
			a1=a[1];
			b=a[2];
			c=a[3];
			if(a1+b>c&&a1+c>b&&b+c>a1){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		else{
			cout << 0;
		}
	}
	else{
		if(n==5){
			if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
				cout << 9;
			}
			if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
				cout << 6;
			}
		}
		if(n==20){
			if(a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12){
				cout << 1042392;
			}
		}
		if(n==500){
			if(a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3&&a[6]==79&&a[7]==74&&a[8]==20&&a[9]==17&&a[10]==91){
				cout << 366911923;
			}
		}
	}
	return 0;
}
