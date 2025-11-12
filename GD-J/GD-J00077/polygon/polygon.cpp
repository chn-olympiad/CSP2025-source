#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,sum;
bool cmp(int v,int b){
	return b<v;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>maxn)
			maxn=a[i];
	}
	if(sum>maxn*2)
		cout<<1;
	else
		cout<<0;
	return 0;
}
