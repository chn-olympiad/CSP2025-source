#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[3],n;
	cin>>n;
	cin>>a[0]>>a[1]>>a[2];
	int num=a[0]+a[1]+a[2];
	int maxn=0;
	for(int i=0;i<3;i++){
		maxn=max(maxn,a[i]);
	}
	maxn*=2;
	if(num>maxn) cout<<1;
	else cout<<0;
	return 0;
}

