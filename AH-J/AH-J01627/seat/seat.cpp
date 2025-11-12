#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],fs,wz;
int cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    fs=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==fs){wz=i;break;}
    if(wz<=n){cout<<1<<' '<<wz;return 0;}
    else{
		int p=wz/n;
		cout<<p+1<<' ';
		if(p%2==0)cout<<wz%n;
		if(p%2)cout<<n+1-wz%n;
	}
    return 0;
}
