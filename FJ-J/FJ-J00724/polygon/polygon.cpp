#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","e",stdin);
	int n,a[10009],q,w=0;
	cin>>n;
	for(int z=1;z<=n;z++){
		cin>>a[z];
	}
	for(int z=3;z<=n;z++){
		for(int x=3;x<=z;x++){
			if(a[x-2]>=a[x-1]&&a[x-2]>=a[x]){
				q=a[x-2];
			}else if(a[x-1]>=a[x-2]&&a[x-1]>=a[x]){
				q=a[x-1];
			}else{
				q=a[x];
			}
			if(a[x-2]+a[x-1]+a[x]>q*2){
				w++;
			}
		}
	}
	cout<<w;
	return 0;
}
