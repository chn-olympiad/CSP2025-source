#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	char f=getchar();
	while(f>'9'||f<'0'){
		f=getchar();
	}
	while(f<='9'&&f>='0'){
		x=x*10+f-'0';
		f=getchar();
	}
}
const int N=1e4+5,M=1e6+5;

int n,m,k,a[12][N],h[N+15],f[N+15];
long long ans=2e18;
struct edge{
	int u,v,w;
	bool operator<(const edge&x) const{
	    return w<x.w;
	}
}e[M+N*10];
int fin(int u){
	return f[u]==u?u:f[u]=fin(f[u]);
}
int mm;
void add(int u,int v,int w){
	mm++;e[mm].u=u,e[mm].v=v,e[mm].w=w;
} 
void jia(int w){
	for(int i=k+n;i>=1;i--){
		f[i]=i;
	}
//	for(int i=1;i<=m;i++){
//		e[i].u=b[i].u,e[i].v=b[i].v,e[i].w=b[i].w;
//	}
	mm=m;
	for(int i=1;i<=k;i++){
		if(w&(1<<(i-1)))
		    for(int j=1;j<=n;j++){
			    add(i+n,j,a[i][j]);
		    }
	}
}
void clear(){
	for(int i=n+k;i>=1;i--){
		f[i]=i;
	}
//	for(int i=1;i<=k;i++){
//		z[i].clear();
//	}
}
void answer(int w){
	clear();
	long long anss=0;
	int tot=n,cnt=1;
	for(int i=1;i<=k;i++){
		if(w&(1<<(i-1))){
			tot++;
			anss=anss+a[i][0];
		}
	}
//	cout<<anss<<endl;
	for(int i=1;i<=mm;i++){
		int u=max(e[i].u,e[i].v)-n;
		if(u>0&&(((1<<(u-1))&w)==0)){
			continue;
		}
		int f1=fin(e[i].u),f2=fin(e[i].v);
		if(f1!=f2){
			f[f1]=f2;
			anss=anss+e[i].w;
		//	cout<<e[i].w<<' ';
			cnt++;
			if(cnt==tot||anss>=ans){
			    break;
		    }
		}
		
	}
//	cout<<endl;
	ans=min(ans,anss);
}
//vector<int> g[13],z[13];

void answer2(int w){
	sort(e+1,e+mm+1);
	long long anss=0;
	int tot=n,cnt=1;
	for(int i=1;i<=k;i++){
		if(w&(1<<(i-1))){
			tot++;
			anss=anss+a[i][0];
		}
	}
	for(int i=1;i<=mm;i++){
		int f1=fin(e[i].u),f2=fin(e[i].v);
		if(f1!=f2){
			f[f1]=f2;
			anss=anss+e[i].w;
			cnt++;
//			int u=max(e[i].u,e[i].v);
//			if(u>n){
//				g[u-n].push(min(e[i].u,e[i].v));
//			}
			if(cnt==tot||anss>=ans){
			    break;
		    }
		}
	}
	ans=min(ans,anss);
	int s=(1<<k)-1;
	for(int i=1;i<=k;i++){
		clear();
		anss=ans;
		answer(s&(~(1<<(i-1))));
		if(ans<anss){
			s=s&(~(1<<(i-1)));
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		int vis=0;
		for(int j=0;j<=n;j++){
			read(a[i][j]);
			if(a[i][j]==0){
				vis++;
			}
		//	cout<<a[i][j]<<" ";
		}
	//	cout<<endl;
		if(!(a[i][0]==0&&vis>=2)){
			flag=0;
		}
    }
    if(flag){
    	jia((1<<k)-1);
    	sort(e+1,e+mm+1);
    	answer((1<<k)-1);
    	printf("%lld",ans);
    	return 0;
	}else if(m<=1e6&&k<=5){
		jia((1<<k)-1);
		sort(e+1,e+mm+1);
		for(int i=(1<<k)-1;i>=0;i--){
		    answer(i);
	    //	cout<<ans<<endl;
	    }  
	}else{
		jia((1<<k)-1);
    	answer2((1<<k)-1);
	}
	printf("%lld",ans);
	return 0;
} 
