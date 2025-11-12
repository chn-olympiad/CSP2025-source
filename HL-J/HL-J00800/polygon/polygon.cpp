#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[1001],s=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=n;j++){
			for(int z=1;z<=n;z++){
				if(a[i]+a[j]+a[z]>2*a[z])s+=1;j++;break;
			}
		}
	}
	cout<<s;
	return 0;
}
