#include<bits/stdc++.h>
#define N 114514
#define int long long
using namespace std;
long long a[N],an[N];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    int n;
    cin>>n;
    for(int  i=1;i<=3;i++)cin>>a[i];
	if(a[1]+a[2]>a[3])cout<<1;
	else cout<<0;
    return 0;
}
