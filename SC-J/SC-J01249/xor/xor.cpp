#include<bits/stdc++.h>
using namespace std;
long long a[1006],ans=0,maxn=-1;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1,ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
		for(int j=1+i;j<=n;j++){
			maxn=max(maxn,a[j]);
			for(int k=j+1;k<=n;k++){
				long long num=a[i]+a[j]+a[k];
				if(num>max(maxn,a[k]*2))ans++;
			}
		}
	}
	cout<<ans/2;
	return 0;
} 