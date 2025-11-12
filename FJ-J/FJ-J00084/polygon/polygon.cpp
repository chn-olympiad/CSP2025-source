#include<bits/stdc++.h>
using namespace std;
long long n,m=998244353,a[100005],ans=0,v[100005];
void za(long long t,long long x,long long y,long long z){
	if(x>=3){
		if(y>z*2){
			ans++;
			ans%=m;
		}
	}
	if(x==n){
		return ;
	}
	for(long long i=t;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			za(i,x+1,y+a[i],max(z,a[i]));
			v[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	za(1,0,0,0);
	cout<<ans<<endl;
	return 0;
} 
