#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
int a[5005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    int maxn=-1;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
	}
    if(a[1]+a[2]+a[3]>maxn*2) cout<<"1";
    else cout<<"0";
    return 0;
}
