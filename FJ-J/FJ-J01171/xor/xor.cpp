#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int n,k,a[500010],ans,v[500001];
inline int r(){
	int n=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){n=n*10+c-'0';c=getchar();}
	return n*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=r();k=r();
	for(int i=1;i<=n;i++){
		a[i]=r();
		if(a[i]==k){
			ans++;v[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)continue;
			int u=0,g=0,o=0;
			bool r=0;
			for(int ii=i;ii<=j;ii++){
				u^=a[ii];
				if(v[ii]==1){
					o=i;
					r=1;g=ii;
					break;
				}
				v[ii]=1;
			}
			if(u==k&&!r){
				ans++;
			}else if(u!=k||r){
				if(r)for(int ii=o;ii<g;ii++)v[ii]=0;
				else for(int ii=i;ii<=j;ii++)v[ii]=0;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
