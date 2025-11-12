#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,a[N],k,ans,s[N],b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
		if(i>1&&a[i]!=a[i-1])f=1;
		if(a[i]>1)f=2;
	}
	if(!f){
		ans+=n/2;
		cout<<ans;
		return 0;
	}
	else if(f<2){
		cout<<ans;
		return 0;
	}
	else{
		if(k!=0){
			for(int i=1;i<=n;i++){
				if(b[i])continue;
				for(int j=i+1;j<=n;j++){
					if(b[j])break;
					if((s[j]-s[i-1])%k==0)ans++;
				}
			}
		}
		else{
			for(int i=2;i<=n;i++){
				if(!b[i]&&!b[i-1]&&a[i]==a[i-1]){
					ans++;
					b[i]=b[i-1]=1;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
