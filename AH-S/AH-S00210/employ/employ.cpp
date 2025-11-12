#include<bits/stdc++.h>
using namespace std;
int d[1000],v[1005],n,m,sf[1005],nx[1005],ans;
void g(){
	int s=0,k=0;
	for(int i=1;i<=n;i++){
		if((sf[i]==0)||(k>=nx[d[i]])){
			k++;
		}else{
			s++;
			if(s==m){
				ans++;
				return;
			}
		}
	}
}
void f(int x){
	if(x==n+1){
		g();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			d[x]=i;
			f(x+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&sf[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&nx[i]);
	}
	f(1);
	printf("%d",ans);
	return 0;
}
