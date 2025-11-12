#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int qzh[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=a[i]^qzh[i-1];
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int count=0;
		int lp=i-1,np=i;
		while(np<=n){
			if((qzh[np]^qzh[lp])==k){
				count++;
				lp=np;
			}
			np++;
		}
		if(count>ans)ans=count;
	}
	cout<<ans;
	return 0;
}
