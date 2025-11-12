#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005];
int f(int mx,int x,int m){
	if(x>=3&&m>mx){
		ans=(ans+1)%998244353;
	}
	for(int i=x;i<n;i++){
		if(a[i]>mx){
			f(a[i],i+1,m+mx);
		}
		else
			f(mx,i+1,m+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	f(0,0,0);
	printf("%d",ans);
	return 0;	
} 
