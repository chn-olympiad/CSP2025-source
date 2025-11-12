#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[1005],ma=0,cnt=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		cnt+=a[i];
	}
	if(n<=3){
		if(ma*2<cnt){
			cout<<1;		
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else{
		cout<<n+1;
	}
}
