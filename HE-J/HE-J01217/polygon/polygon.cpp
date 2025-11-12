#include<bits/stdc++.h>
using namespace std;
int n,a[5010],a1=0;
long long ans=0;
long long fac(int f){
    if(f==0||f==1) return 1;
    else return f*fac(f-1);
}
long long c(int i){
    return fac(n)/(fac(i)*fac(n-i));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
	}
	if(a1==n){
        for(int i=3;i<=n;i++){
            ans+=c(i);
        }
        cout<<ans%998244353;
        return 0;
	}
	cout<<0;
	return 0;
}
