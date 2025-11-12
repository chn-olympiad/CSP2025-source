#include<bits/stdc++.h>
using namespace std;
int n,k,t,ans,a[500010],f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=100&k<=1||n<=10){
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			if(t>0){
				t^=x;
			}else{
				t=x;
			}
			if(t==k) t=-1,ans++;
		}
	}else{
		int last=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[i]=f[i-1]^a[i];
			if(i==1) f[i]=a[i];
			for(int j=i;j>=last;j--){
				if((f[i]^f[j])==k){
					ans++;
					last=i;
					break;
				}
			}
		}
	}
	cout<<ans;
 return 0;
} 
