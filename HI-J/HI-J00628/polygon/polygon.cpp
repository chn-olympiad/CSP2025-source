#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,cnt=0,su=0;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]*2<sum){
			cnt++;
		}
		if(cnt==n){
			su++;
		}
	}
	cout<<su;
	return 0;
}
