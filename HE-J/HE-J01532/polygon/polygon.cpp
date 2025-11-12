#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],s[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=2,x=3;
	for(i=1;i<j;i++){
		for(j=i+1;j<x;j++){
			for(x=j+1;x<=n;x++){
				if(a[i]+a[j]+a[x]>a[x]*2){
					ans++;
					//cout << a[i] <<" "<< a[j]<<" "<< a[x]<<endl;
				}
				if(x!=n){
					for(int y=x+1;y<=n;y++){
						if(a[i]+a[j]+a[x]+a[y]>a[y]*2){
							ans++;
						}
					}
				}
			}
		}
	}
	ans+=1;
	cout << ans%998244353;
	return 0;
}
