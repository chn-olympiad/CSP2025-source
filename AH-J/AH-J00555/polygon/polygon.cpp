#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],cnt=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[1]+a[2]>max(a[1],a[2])*2) cnt++;
	if(a[2]+a[3]>max(a[3],a[2])*2) cnt++;
	if(a[1]+a[3]>max(a[1],a[3])*2) cnt++;
	if(a[1]+a[2]+a[3]>max(a[3],max(a[1],a[2]))*2) cnt++;
	cout<<cnt;
	return 0;
}
