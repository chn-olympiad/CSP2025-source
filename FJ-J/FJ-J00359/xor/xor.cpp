#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10001000],b[10001000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(b[a[1]]==n&&k==0){
		cout<<n/2;
		return 0;
	}else if(k==0){
		int ans=0;
		for(int i=1;i<=n;){
			if(a[i]==0){
				ans++;
				i++;
			}else if(a[i]==a[i+1]){
				ans++;
				i=i+2;
			}else{
				i++;
			}
		}
		cout<<ans;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int p=0;
				for(int o=i;o<=j;o++){
					p=p&a[o];
				} 
				if(p==k){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
