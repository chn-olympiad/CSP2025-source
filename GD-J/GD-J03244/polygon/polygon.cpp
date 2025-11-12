#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxn,len;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		maxn=max(a[1],max(a[2],a[3]));
		len=a[1]+a[2]+a[3];
		if(len>=2*maxn) cout<<1;
		else cout<<0;
	}else{
		sort(a+1,a+1+n);
		cout<<a[n]+a[n-1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
