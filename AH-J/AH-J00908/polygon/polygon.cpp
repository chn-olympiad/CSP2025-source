#include<bits/stdc++.h>
using namespace std;
long long i,k,n,cnt,maxn,ans,a[100010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<3){
	    cout<<0;
	}else if(n==3){
	    if(ans>2*maxn){
	        cout<<1;
	    }else{
	        cout<<0;
	    }
	}
    return 0;
}
