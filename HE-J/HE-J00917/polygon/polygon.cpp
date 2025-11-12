#include<bits/stdc++.h>
using namespace std;
int a[500001],n,k,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
	} 
	k=max(a[1],max(a[2],a[3]));
	if(a[1]+a[2]+a[3]>k*2)cout<<1;
	else cout<<0;
	return 0;
}
