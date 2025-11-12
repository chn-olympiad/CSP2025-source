#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,d,s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				d=max(a[i],max(a[j],a[z]));
				if(a[i]+a[j]+a[z]>a[d]*2) s++;
			}
		}
	}
	cout<<s;
	
	return 0;
} 