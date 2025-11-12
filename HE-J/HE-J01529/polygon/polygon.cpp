#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b,c[1000001],ans;
int main(){
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+b);
	/for(int i=1;i<=b;i++){
		c[i]=a[i]+c[i-1];
	}
	for(int i=b;i>=3;i--){
		for(int u=3;u<=i;u++){
			if(c[i-1]-c[i-u]>a[i]){
				ans=ans+i-u+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
