#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],x,y,l,r,s;
bool tf;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	tf=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=b[i-1]+a[i];
		if(a[i]!=1){
			tf=0;
		}
	}
	if(tf){
		for(int i=1;i<=n;i++){
			x=x*i;
		}
		cout << x/n;
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(b[i]>a[i]*2){
			s++;
		}
		for(int j=i-1;j>=3;j--){
			for(int k=j;k>=i-j;k--){
				if(b[i]-b[k]+b[k-(i-j)]>a[i]*2){
					s++;
				}
			}
		}
	}
	cout << s;
	return 0;
}
