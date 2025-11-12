#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=0,da=0;
		for(int k=1;k<=n;k++){
			for(int l=1;l<=n;l++){
				for(int j=k;j+i-1<=n;j+=l){
					s+=a[j];
					if(a[j]>da){
						da=a[j];
					}
				}	
			}
		}	
		if(da==1){
			cout<<n;
			return 0;
		}
		if(s>da*2){
			ans++;
		}
	}
	cout<<ans;	
	return 0;
}
