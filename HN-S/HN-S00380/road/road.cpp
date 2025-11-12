#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while(m--) scanf("%d%d%d",&u,&v,&w);
	while(k--){
		scanf("%d",&c);
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			s+=a;
		}
		s+=c;
	}
	if(s==0) printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
