#include<bits/stdc++.h>
using namespace std;
int s[1<<20];
const int N=5e5+7;
int a[N],k,f[N],n; 
int read(){
	char ch=getchar();
	int k=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f;
}
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(s,-1,sizeof(s));
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read(),a[i]=a[i]^a[i-1];
	s[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]);
		int w=a[i]^k,w2=k^a[i];
		if(s[w]!=-1) f[i]=max(f[i],f[s[w]]+1);
		if(s[w2]!=-1) f[i]=max(f[i],f[s[w2]]+1); 
		s[a[i]]=i;
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
}
