#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k;
int a[N];
bool flag1=1,flag2=1;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) flag1=0;
		if(a[i]>1) flag2=0;
	}
	if(flag1) cout<<n;
	else if(flag2){
		int ans=0,sum=-1;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				sum=-1;
			}else{
				if(sum==-1) sum=a[i];
				else sum=sum^a[i];
				if(sum==k){
					ans++;
					sum=-1;
				}
			}
		}
		cout<<ans;
	}else{
		int ans=0,sum=-1,mn=0,la=0;
		bool fg=0;
		while(mn<n){
			mn=n;
			for(int i=la+1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(i==j) sum=a[j];
					else sum=sum^a[j];
					if(sum==k){
						ans++;
						mn=min(mn,j);
						fg=1;
						break;
					}
				}
				if(fg) break;
			}
			la=mn;
		}
		cout<<ans;
	}

	return 0;
}

