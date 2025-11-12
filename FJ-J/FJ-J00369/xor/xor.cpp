#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,ans,s[500005],x=1,y=1,z=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)y=0;
		if(a[i]!=0&&a[i]!=1)z=0;
		if(a[i]==m){
			s[i]=x;
			x++;
		}
	}
	if(y==1){
		cout<<n/2;
		return 0;
	}
	if(z==1){
		if(m==0){
			int o=0;
			for(long long i=1;i<=n;i++){
				if(o==1&&a[i]==1){
					ans++;
					o=0;
					continue;
				}
				if(o==1)o=0;
				if(a[i]==0)ans++;
				else o=1;
			}
		}
		else{
			for(long long i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<=n-i;j++){
			long long w=a[j],t=0;
			for(long long k=j+1;k<=j+i;k++){
				w=w^a[k];
				if(s[k]!=0){
					t=1;
					break;
				}
			}
			if(t==1)continue;
			if(w==m){
				for(long long k=j;k<=j+i;k++){
					s[k]=x;
				}
				x++;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(s[i]!=0){
			if(s[i]!=s[i-1])ans++;
		}
	}
	cout<<ans;
	return 0;
}
