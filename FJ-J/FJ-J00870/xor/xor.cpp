#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[500005];
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0||a[i]>1){
			flag=false;	
		}
	}if(flag==true){
		if(m>=2){
			cout<<0;
			return 0;
		}else if(m==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}cout<<ans<<endl;
		}else if(m==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0||(a[i]==1&&a[i+1]==1)){
					ans++;
					if(a[i+1]==1) a[i+1]=-1;
				}
			}cout<<ans<<endl;
		}return 0;
	}int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==m) ans++;
	}cout<<ans;
	return 0;
}
