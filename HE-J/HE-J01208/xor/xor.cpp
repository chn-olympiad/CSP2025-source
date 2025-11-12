#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		int count=0,cnt=1,num=a[1];
		for(int j=1;j<=cnt;j++) num^=j;
		if(num==k) count++;
		num=a[cnt];
		for(int j=cnt;j<=n;j++) num^=j;
		if(num==k) count++;
		cnt++,ans=max(ans,count);
}
	cout<<ans;
	return 0;
}
