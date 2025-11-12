#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[50000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(i+3<=n+1){
			int maxn=-100000;
			int count=a[i]+a[i+1];
			if(a[i]>a[i+1]){
				maxn=a[i];
			}
			else{
				maxn=a[i+1];
			}
			for(int j=3;j<=n-i;j++){
				count+=a[i+j];
				if(maxn<a[i+j]){
					maxn=a[i+j];
				}
				if(maxn*2<count){
					ans++;
				}
			}
		}
	}
	cout<< ans;
	int mo=ans%998;
	mo%=224;
	mo%=353;
	cout << mo;
	return 0;
}
