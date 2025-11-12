#include<bits/stdc++.h>
using namespace std;
long long n,a[30],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*a[i]){
					cnt++;
				}else{
					break;
				}
			}
		}
	}
	cout<<cnt;
}
