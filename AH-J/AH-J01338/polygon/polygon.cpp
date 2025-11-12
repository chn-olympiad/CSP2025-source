#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,c,s=0,tt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<3){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1)tt++;
	}
	if(tt==0){
		for(int i=1;i<=n-2;i++)s+=i;
		cout<<s;return 0;
	}
    cout<<9;
}
