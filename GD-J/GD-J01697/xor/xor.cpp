#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],vis[500010],ans;
ll read(){
	ll cnt=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) cnt=cnt*10+ch-'0';
	return cnt*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	time_t start=clock();
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1,flag=0;
			ll res=0;
			for(int k=i;k<=j;k++){
				res^=a[k];
				if(vis[k]){
					flag=1;
					break;
				}
			}
			if(flag) continue;
			if(res==m){
				for(int k=i;k<=j;k++) vis[k]=1;
				ans++;
			}
		}
	}
	cout<<ans;
//	time_t duration=clock()-start;
//	cout<<'\n'<<duration<<"ms";
	return 0;
}
