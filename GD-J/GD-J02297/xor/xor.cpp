//ccf orz
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
const int N=5e5+10;//60tps
int n,k,a[N],ans;
vector<int> e[N];
int f[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	//----------------------------------------
	for(int i=1;i<=n;i++){
		int j=i+1,s=a[i];
		if(s==k) e[i].push_back(i+1);
		while(j<=n){
			s^=a[j];
			if(s==k) e[i].push_back(j+1);
			j++;
		}
	}
	//----------------------------------------
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]);
		for(auto x:e[i]){
			f[x]=max(f[x],f[i]+1);
		}
	}
	for(int i=1;i<=n+1;i++) ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}
