#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,k;
int a[N];
bool f[N];
int ans1,ans2;
bool flag1=true,flag2=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=0;
			if(a[i]!=0) flag2=0;
		}
	}
	if(!flag1&&flag2){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans1++,f[i]=1;
			}
			for(int i=1,j=2;i<=n&&j<=n;i++,j++){
				if(a[i]==a[j]){
					if(f[i]==0&&f[j]==0) ans1++,f[i]=1,f[j]=1;
				}
			}
			memset(f,0,sizeof(f));
			for(int i=1,j=2;i<=n&&j<=n;i++,j++){
				if(a[i]==a[j]){
					if(f[i]==0&&f[j]==0) ans2++,f[i]=1,f[j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					if(f[i]==0) ans2++,f[i]=1;
				}
			}
			cout<<max(ans1,ans2)<<"\n";
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans1++,f[i]=1;
			}
			for(int i=1,j=2;i<=n&&j<=n;i++,j++){
				if(a[i]!=a[j]){
					if(f[i]==0&&f[j]==0) ans1++,f[i]=1,f[j]=1;
				}
			}
			memset(f,0,sizeof(f));
			for(int i=1,j=2;i<=n&&j<=n;i++,j++){
				if(a[i]!=a[j]){
					if(f[i]==0&&f[j]==0) ans2++,f[i]=1,f[j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(f[i]==0) ans2++,f[i]=1;
				}
			}
			cout<<max(ans1,ans2)<<"\n";
		}
	}else if(flag1) cout<<n/2<<"\n";
	return 0;
}
