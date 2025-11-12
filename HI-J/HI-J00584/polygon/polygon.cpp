#include<bits/stdc++.h>
using namespace std;
int n,a[5010],r[5010],mod=998244353,ans=0,f[5010];
void px(int s,int e){
	if(s==e) return ;
	int mid=(s+e)/2,d=1,i=s,j=mid+1;
	px(s,mid);
	px(mid+1,e);
	
	while(i<=mid && j<=e){
		if(a[i]<=a[j]){
			r[d++]=a[i++];
		}
		else{
			r[d++]=a[j++];
		}
	}
	while(i<=mid){
		r[d++]=a[i++];
	}
	while(j<=e){
		r[d++]=a[j++];
	}
	d=1;
	for(int i=s;i<=e;i++) a[i]=r[d++];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	px(1,n);
	for(int i=3;i<=n;i++){
		for(int j=i-1;j>=2;j--){
			for(int k=j-1;k>=1;k--){
				if(a[k]+a[j]>a[i]){
					if(f[j]==0 && f[k]==0) f[i]+=1;
					else f[i]=(max(k-1,1)*(f[k]+f[j]))%mod;
				} 
			}
		}
		ans=(ans+f[i])%mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

