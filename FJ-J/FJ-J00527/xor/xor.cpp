#include<bits/stdc++.h>
#define int long long

using namespace std;
int T;
int l=-1,r=-1,ans=0;
int a[500005],b[500005];
int read(){
	int sgn=0,ret=0;
	char chr=getchar();
	while (!isdigit(chr)) sgn|=chr=='-',chr=getchar();
	while (isdigit(chr)) ret=ret*10+chr-'0',chr=getchar();
	return sgn ? -ret:ret;
}
void solve(){
	int n=read();
	int k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		int c= b[i-1]^b[j];
			if(c==k){
				if(l==-1){
					l=i;
					r=j;
					ans++;
				}else if(r<i){
					ans++;
					l=i;
					r=j;
				}else if(j<r){
					l=i;
					r=j;
				}
				break;
			}
		}
	}
	
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	T=1;
	for (int t=0;t<T;t++) solve();
	return 0;
}

 
