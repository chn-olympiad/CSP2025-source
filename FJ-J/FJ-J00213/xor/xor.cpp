#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],c[500005],s,f,ans,p,q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			p=i;
			q=i+l-1;
			s=b[q]^b[p-1];
			if(s==k){
				f=1;
				for(int j=p;j<=q;j++){
					if(c[j]==1){
						f=0;
						break;
					}
				}
				if(f && s==k){
					c[p]=1;
					c[q]=1;
					ans++;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
