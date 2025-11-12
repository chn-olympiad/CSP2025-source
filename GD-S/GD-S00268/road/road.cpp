#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define PLL pair<LL,LL>
#define pb push_back

const int N=3e5+6;
const int M=1.5e6+6;

LL T,n,m,k,sum,cnt,nans,ans,a,b,c,inf=1e16;
LL A[N][12],B[N],D[N];
vector<PLL> E[N];

LL fd(LL x){
	if(B[x]==x)return x;
	return B[x]=fd(B[x]);
}

struct lop{
	LL x,y,z;
	void sdp(LL tx,LL ty,LL tz){
		x=tz;y=ty;z=tz;
		return ;
	}
}C[N];

bool cmp(lop xz,lop yz){
	if(xz.z==yz.z){
		if(xz.x==yz.x)return xz.y<yz.y;
		return xz.x<yz.x;
	}
	return xz.z<yz.z;
}

LL read(){
	LL x;
	scanf("%lld",&x);
	return x;
}

struct kpue{
	LL dt=3e5+1,dw=3e5;
	lop du[M];
	void clear(){
		dt=3e5+1;dw=3e5;
		return ;
	}
	bool empty(){
		return dt>dw;
	}
	lop dtop(){
		return du[dt];
	}
	lop top_back(){
		return du[dw];
	}
	void dpop(){
		dt++;
		return ;
	}
	void pop_back(){
		dw--;
		return ;
	}
	void push_back(lop x){
		du[++dw]=x;
		return ;
	}
	void push_front(lop x){
		du[--dt]=x;
		return ;
	}
}dl,pl,tl;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		sum=read();cnt=read();ans=read();
		if(sum>cnt)swap(sum,cnt);
		C[i].sdp(sum,cnt,ans);
	}
	sort(C+1,C+m+1,cmp);
	for(int i=1;i<=m;i++){
		dl.push_back(C[i]);
	}
	for(int i=1;i<=k;i++){
		D[i]=read();b+=D[i]; 
		for(int j=1;j<=n;j++){
			A[j][i]=read();
			c=min(c,A[j][i]);
		}
		b+=c;
	}
	ans=inf;
	if(b==0){
		LL i=(1<<k)-1;
		cnt=0;sum=n-1;nans=0;
		for(int j=1;j<=n;j++){
			B[j]=j;
		}
		for(int j=1;j<=k;j++){
			if(((1<<(j-1))&i)){
				nans+=D[j];
				for(int ap=1;ap<=n;ap++){
					C[++cnt]={ap,j+n,A[ap][j]};
				}
				sum++;
				B[j+n]=j+n;
			}
		}
		sort(C+1,C+cnt+1,cmp);
		a=1;
		while(sum>0){
			lop u=dl.dtop();
			if(fd(u.x)==fd(u.y)){
				tl.push_back(dl.dtop());dl.dpop();
				continue;
			}
			while(fd(C[a].x)==fd(C[a].y)){
				a++;
			}
			if(u.z<=C[a].z){
				nans+=u.z;
				B[fd(u.x)]=fd(u.y);
				tl.push_back(dl.dtop());dl.dpop();
			}
			else{
				nans+=C[a].z;
				B[fd(C[a].x)]=fd(C[a].y);
				a++;
			}
			sum--;
		}
		ans=min(ans,nans);
		while(!tl.empty()){
			dl.push_front(tl.top_back());
			tl.pop_back();
		}
		cout<<ans<<endl;
		return 0;
	}
	ans=inf;
	for(LL i=0;i<(1<<k);i++){
		cnt=0;sum=n-1;nans=0;
		for(int j=1;j<=n;j++){
			B[j]=j;
		}
		for(int j=1;j<=k;j++){
			if(((1<<(j-1))&i)){
				nans+=D[j];
				for(int ap=1;ap<=n;ap++){
					C[++cnt]={ap,j+n,A[ap][j]};
				}
				sum++;
				B[j+n]=j+n;
			}
		}
		sort(C+1,C+cnt+1,cmp);
		a=1;
		while(sum>0){
			lop u=dl.dtop();
			if(fd(u.x)==fd(u.y)){
				tl.push_back(dl.dtop());dl.dpop();
				continue;
			}
			while(fd(C[a].x)==fd(C[a].y)){
				a++;
			}
			if(u.z<=C[a].z){
				nans+=u.z;
				B[fd(u.x)]=fd(u.y);
				tl.push_back(dl.dtop());dl.dpop();
			}
			else{
				nans+=C[a].z;
				B[fd(C[a].x)]=fd(C[a].y);
				a++;
			}
			sum--;
		}
		ans=min(ans,nans);
		while(!tl.empty()){
			dl.push_front(tl.top_back());
			tl.pop_back();
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}
