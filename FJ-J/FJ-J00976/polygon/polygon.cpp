#include<bits/stdc++.h>
using namespace std;
int n,sum,a[1000000],b[1000000];
bool f=0,k=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]>0){
    		k=1;
		}
	}
	if(n<3||k==0){
		cout<<0;return 0;
	}
if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			
			sum++;
		}
		if(a[1]+a[3]+a[2]>a[2]*2){
			sum++;
		}
		if(a[3]+a[2]+a[1]>a[1]*2){
			sum++;
		}
		cout<<sum;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			if(a[i]!=a[j]){
				f=1;
			}
		}
	}
	if(!f){
		int s=1;
		for(int i=n+1;i>=2;i--){
			s*=i;
		}
		cout<<s;return 0;
	}else cout<<1;
	int ans=0;
	for(int i=2;i<=n-1;i++){
		
		for(int j=1;j<=n-i+1;j++){
			int ss=0;
			int maxn=0;
			
			for(int k=j;k<=j+i;k++){
				ss+=a[k];maxn=max(maxn,a[k]);
			}
			if(maxn*2<ss){
				ans++;
				
			}
		}
	}
	cout<<ans;
	return 0;
}
