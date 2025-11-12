#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int f[500001],maxf[500001]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool bj=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1){
			bj=0;
		}
	}
	if(bj){
		if(k>1){
			cout<<0;
			return 0;
		}
		int yhh=0;
		int s=0;
		for(int i=1;i<=n;i++){
			yhh^=a[i];
			if(yhh==k){
				s++;
				yhh=0;
			}
		}
		cout<<s;
	}else{
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
			int yhh=0;
			for(int j=i;j>=1;j--){
				yhh^=a[j];
				if(yhh==k){
					f[i]=max(f[i],maxf[j-1]+1);
					break;
				}
			}
			maxf[i]=max(maxf[i-1],f[i]);
		}
		cout<<f[n];
	}
	return 0;
}
