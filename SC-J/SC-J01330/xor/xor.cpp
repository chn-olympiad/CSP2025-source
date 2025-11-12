#include<bits/stdc++.h>
using namespace std;
int a[500010],sum[500010];
int read(){
	int x=0,p=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while((ch>='0' and ch<='9')){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*p;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	int l=1,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=l;j--){
			if((sum[i]^sum[j-1])==k){
				ans++;
				l=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}