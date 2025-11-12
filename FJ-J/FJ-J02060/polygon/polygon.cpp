#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(i==j || i==k || j==k)continue;
				if(a[i]+a[j]+a[k]>(2*(max(max(a[i],a[j]),a[k]))))cnt++;
			}
		}
	}
	cout << cnt%998%244%353;
	return 0;
}
