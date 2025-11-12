#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],ans,s[1000001],f[1000001],m,l=1;
bool v1,v2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		if(a[i]==k){
			f[++m]=i;
			s[i]=0;
			ans++;
		}
		if(a[i]>1)v2=1;
		if(a[i]!=1)v1=1;
	}
	f[++m]=n;
	if(k==0&&!v1){
		cout<<n/2;
	}
	else if(k==1&&!v2){
		cout<<ans;
	}
	else{
		for(int i=0;i<n;i++){
			if(i>=f[l])l++;
			for(int j=i+2;j<=f[l];j++){
				if(a[j]!=k&&(s[j]^s[i])==k){
//					cout<<i<<' '<<j<<'\n';
					i=j;
					ans++;
					break;
				}
			}
		}
		cout<<ans*3;
	}
	return 0;
}
