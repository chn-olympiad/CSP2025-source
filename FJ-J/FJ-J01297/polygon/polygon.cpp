#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		} 
		else{
			if(a[1]+a[2]>a[3]){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
			
			}
		}
	if(mx==1){
		cout<<n-2;
	}
	return 0;
}
