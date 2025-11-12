#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool fa=1,fb=1,fc=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fa=0;
		if(a[i]!=1&&a[i]!=0) fb=0;
		if(a[i]>255) fc=0;
	}
	if(fa){
		cout<<n/2;
		return 0;
	}else if(fb){
		if(k==0){
			bool p1=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(!p1&&a[i]==1) p1=1;
				else if(p1&&a[i]==1) p1=0,ans++;
				else if(p1&&a[i]==0) p1=0,ans++;
				else if(!p1&&a[i]==0) ans++;
			}
			cout<<ans;
			return 0;
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
	        }
	        cout<<ans;
	        return 0;
		}
	}else{
		bool flag=0;
		int now=-1,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				if(flag){
					flag=0;
					now=-1;
				}
			}else{
				if(flag){
					now=now^a[i];	
				}else{
					now=a[i];
					flag=1;
				}
				if(now==k){
					flag=0;now=-1;
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
