#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[10010]={},b=0,cnt=0,d=0,max=0,z=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

