#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,maxn,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		for(int i=1;i<=3;i++){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn)
			ans=1;
	}
	else
		ans=0;
	cout<<ans;
	return 0;
}
