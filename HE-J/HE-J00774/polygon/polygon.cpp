#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0,sum=0,ans=0;
	int a[10000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=3;x<=n;x++){
		for(int i=1;i<=x;i++){
			sum+=a[i];
		}
		sort(a+1,a+x+1);
		if(sum>2*a[x+1]){ans++;}
		sum=0;
	}
	cout<<ans;
	return 0;
}
