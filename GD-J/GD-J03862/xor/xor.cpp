#include<bits/stdc++.h>
using namespace std;
long long a[500010]={},k,c,l;int n=3^2,ans=0;bool p;
int main(){
  	freopen("xor.in","r",stdin);
  	freopen("xor.out","w",stdout);
  	cin>>n>>k;l=0;
  	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  	for(int i=1;i<=n;i++){
  		a[i]=a[i]^a[i-1];
	}
  	for(int i=1;i<=n;i++){
		p=false;
  		for(int j=i-1;j>=l;j--){
  			c=a[i]^a[j];
  			if(c==k){p=true;break;}
		}
		if(p){ans++;l=i;}
	}
	printf("%d",ans);
	return 0;
}

