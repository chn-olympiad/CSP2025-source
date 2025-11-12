#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],sum=0,b[1000000],now=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m)now++;
		b[i]=b[i-1]+a[i];
	}
	if(m==0){
	int l=1,r=1;
	while(l<=n &&r<=n){
    if(b[r-1]-b[l-1]==b[r]){
    	sum++;
    	r++;
    	l=r;
	}
	else {
		r++;
	}
	}
	int p=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)p++;
	}
	cout<<max(sum,p);
		return 0;
	}
	int l=1,r=1;
	while(l<=n &&r<=n){
		if(b[r]-b[l-1]<m){
			r++;
		}
		else if((b[r]-b[l-1])%m==0){
			sum++;
			l=r+1;
			r++;
			
		}
		else if(b[r]-b[l-1]>m){
			l++;
		}
	}
	cout<<max(sum,now);
	return 0;
}
