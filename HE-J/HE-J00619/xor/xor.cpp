#include<bits/stdc++.h>
using namespace std;
bool b[500000];
int yihuo(int a,int b){
	int aa[100],bb[100],ii=100,jj=100,cc[100],ans=0;
	for(int i=0;i<100;i++){
		aa[i]=0;bb[i]=0;cc[i]=0;
	}
	while(a){
		ii--;
		aa[ii]=a%2;
		a=int(a/2);
	}
	while(b){
		jj--;
		bb[jj]=b%2;
		b=int(b/2);
	}
	int k=min(ii,jj),bjydk=k;
	while(k<=99){
		if(aa[k]==bb[k]){
			cc[k]=0;
		}
		else{
			cc[k]=1;
		}
		k++;
	}
	int m=1;
	for(int i=99;i>=bjydk;i--){
		ans+=cc[i]*m;
		m*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=0,wles=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int k=j;k<j+i;k++){
				if(b[k]==1){
					wles=1;
					break;
				}
				flag=yihuo(flag,a[k]);
			}
			if((flag==k)&&(wles==0)){
				ans++;
				for(int k=j;k<j+i;k++){
					b[k]=1;
				}
			}
			flag=0,wles=0;
		}
	}
	cout<<ans;
	return 0;
}
