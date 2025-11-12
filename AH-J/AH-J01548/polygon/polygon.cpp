#include<bits/stdc++.h>
using namespace std;
long long f[5000][5000];
long long i,n,a[50110],z,j,ans;
void d(long long x,long long c){
	if(c==i){
	    if(x>a[i]){
		    ans++;
		    return;	
		}else{
			return;
		}	
	}
	d(x+a[c],c+1);
	d(x,c+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=0;
	for(i=3;i<=n;i++){
		d(0,1);
	}
	cout<<ans<<endl;
    return 0;
}
