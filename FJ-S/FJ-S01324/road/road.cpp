#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,z[10101],dl[1100][1110],ans,c[10101],x,y;
struct op{
	long long x,y,z;
}e[1011001];
bool cmp(op a,op b){
	return a.z<b.z;
}
long long f(long long aa){
	if(z[aa]==aa){
		return aa; 
	} 
	return z[aa]=f(z[aa]);
}
void op(long long aa,long long  bb){
	z[f(aa)]=z[f(bb)]; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	
	if(k==0){
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z);
		}	
		for(int i=1;i<=k;i++){
			scanf("%lld",&c[0]);
			for(int j=1;j<=n;j++){
				scanf("%lld",&c[j]);
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++){
			z[i]=i;	
		}
		t=0;
		for(int i=1;i<=m;i++){
			if(f(e[i].x)!=f(e[i].y)){
				
				t++;
				op(e[i].x,e[i].y);
				ans+=e[i].z;
			}
			if(t==n-1){
				break;
			}
		}	
		cout<<ans;
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dl[i][j]=1111111111;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z);
			x=e[i].x;
			y=e[i].y;
			dl[x][y]=e[i].z;
			dl[y][x]=e[i].z;
		}
		for(int i=1;i<=k;i++){
			scanf("%lld",&c[0]);
			for(int j=1;j<=n;j++){
				scanf("%lld",&c[j]);
			}
			for(int j=1;j<=n;j++){
				for(int kk=1;kk<=j-1;kk++){
					if(kk==j) continue;
					dl[j][kk]=min(dl[j][kk],c[j]+c[kk]);
					
				}
			}
			
		}
		int uuu=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				if(i==j) continue;

				uuu++;
				e[uuu].x=i;
				e[uuu].y=j;
				e[uuu].z=dl[i][j];
			}
		}
		sort(e+1,e+uuu+1,cmp);
		for(int i=1;i<=n;i++){
			z[i]=i;	
		}
		t=0;
		for(int i=1;i<=uuu;i++){
			
			if(f(e[i].x)!=f(e[i].y)){
				
				t++;
				op(e[i].x,e[i].y);
				ans+=e[i].z;
			}
			if(t==n-1){
				break;
			}
		}	
		cout<<ans;
	}
	return 0;
} 
