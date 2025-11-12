#include<bits/stdc++.h> 
using namespace std;
int a[5010];
int main(){
	//不管了，先骗分再说！！！！！！！！！！！
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int maxn=max(a[1],max(a[2],a[3]));
		if(maxn*2<a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
	}
	else if((a[1]==a[2]&&a[2]==a[3])&&a[3]==1)
	return 0;
}
