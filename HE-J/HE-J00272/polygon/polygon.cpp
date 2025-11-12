#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans=0;
int a[5050];
int b[5050];
bool f=true;
int mm;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			mm++;
		}
		if(a[i]>1){
			f=false;
		}
	}
	if(f){
		int k=mm*(mm-1)*(mm-2);
		int q=1*2*3;
		ans=(k/q);
		for(int i=mm-3,j=4;i>=1,j<=mm;i--,j++){
			k*=i;
			q*=j;
			ans+=(k/q);
		}
	}else{
		for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				b[j]=1;
			}else{
				b[j]=0;
			}
		}
		int mx=0;
		int s=0;
		for(int j=1;j<=n;j++){
			if(b[j]){
				mx=max(mx,a[j]);
				s+=a[j];
			}
		}
			if(s>2*mx){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

