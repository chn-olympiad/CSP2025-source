#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k,f[500010],mxf[500010];
bool fl[500010],mxfl[500010];
int dfs(int fr){
	if(fr>=n-1) return 0;
	if(fl[fr]) return f[fr];
	else{
		int x=a[fr];
		if(x==k){
			if(!mxfl[fr]){
				int maxx=0;
				for(int j=fr+1;j<n;j++){
					if(!fl[j]){
						f[j]=dfs(j);
						fl[j]=1;
					} 
					maxx=max(maxx,f[j]);
				}	
				mxfl[fr]=1;
				mxf[fr]=maxx;
			}
			fl[fr]=1;
			f[fr]=mxf[fr]+1;
			return f[fr];
		}
		for(int i=fr+1;i<n;i++){
			x^=a[i];
			if(x==k){
				if(!mxfl[i]){
					int maxx=0;
					for(int j=i+1;j<n;j++){
						if(!fl[j]){
							f[j]=dfs(j);
							fl[j]=1;
						} 
						maxx=max(maxx,f[j]);
					}
					mxfl[i]=1;
					mxf[i]=maxx;
				}
				fl[fr]=1;
				f[fr]=mxf[i]+1;
				return f[fr];
			}
		}
		fl[fr]=1;
		f[fr]=0;
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int ma=0;
	for(int i=0;i<n;i++)
		ma=max(ma,dfs(i));
	cout<<ma;
	return 0;
}
