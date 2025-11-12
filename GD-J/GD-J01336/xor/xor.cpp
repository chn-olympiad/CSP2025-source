#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,k,ans,p[N];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1,x;i<=n;++i) x=read(),p[i]=p[i-1]^x;
	for(int l=1,r=1;l<=n && r<=n;){
		if(p[l-1]^p[r]==k) ++r,l=r,++ans;
		while((p[l-1]^p[r])<k) ++r;
		while((p[l-1]^p[r])>k) ++l;
		if(l>r) ++l,r=l;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
