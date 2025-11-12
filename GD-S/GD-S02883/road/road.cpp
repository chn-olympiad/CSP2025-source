#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,head[5000000],tot,w[5000000],sum,fa[5000000],ok[5000000],ans=1e18,okk[1000000];
ll read(){
	char ch=getchar();
	ll ls=0;
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
//		cout<<"?"<<ch<<endl;
		ls*=10;
		ls+=ch-'0';
		ch=getchar();
	}
	return ls;
}
struct nood{
	ll x,y,z;
}es[5000000];
bool cmp(nood x,nood y){
	return x.z<y.z;
}
ll find(ll x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	ll xx=find(x);
	ll yy=find(y);
	if(xx!=yy){
		fa[xx]=yy;
	}	
}
void doo(ll ls){
//	cout<<ls<<"::\n";
	ll js=0,yg=n,sl=0;
	for(int i=0;i<=n+k+1;i++){
		ok[i]=0;
	}
	for(int i=0;i<k;i++){
		if(((ls>>i)&1)){
			if(okk[i]){
				return;
			}
			sl++;
			ok[i+n+1]=1;//某一个k行不行 
			js+=w[i+n+1];
			yg++;//有多少个点会最终被接在一起 
		}
	}
	if(yg==1){
		ans=min(ans,js);
//		cout<<js<<"!\n";
		return;
	}
//	cout<<yg<<"??"<<endl;
	for(int i=1;i<=tot;i++){
		if((es[i].x<=n||ok[es[i].x])&&(es[i].y<=n||ok[es[i].y])){
//			cout<<es[i].x<<"and"<<es[i].y<<endl;
			if(find(es[i].x)!=find(es[i].y)){
				js+=es[i].z;
				merge(es[i].x,es[i].y);
				yg--;
			} 
			if(yg==1){
//				cout<<js<<"!\n";
				if(js<ans){
//					cout<<sl<<"*\n";
				} 
				ans=min(ans,js);
				return;
			}
			if(js>ans){
				return;
			}
		}
	}
}
int main(){
//	n=read();m=read();
//	cout<<n<<"?"<<m<<endl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
//	scanf("%lld",&n);scanf("%lld",&m);scanf("%lld",&k);
	ll x;
	for(int i=1;i<=m;i++){
		++tot;
		es[tot].x=read();es[tot].y=read();es[tot].z=read();
//		scanf("%lld",&es[tot].x);scanf("%lld",&es[tot].y);scanf("%lld",&es[tot].z);
	}
	for(int i=1;i<=k;i++){
		w[n+i]=read(); 
		for(int j=1;j<=n;j++){
			x=read();
			tot++;
			es[tot].x=n+i,es[tot].y=j,es[tot].z=x;
		}
	}
	//如果加上我了以后答案没有更优，说明我肯定是没用的，那就可以不要我了 
	sort(es+1,es+tot+1,cmp);
	for(int j=1;j<=n+k+1;j++){
		fa[j]=j;
	}
	doo(0);
	if(n>=8&&m>=500000&&n>1000){
		ll lss=ans;//临时记录答案
		for(int i=0;i<k;i++){
			ans=1e18;
			for(int j=1;j<=n+k+1;j++){
				fa[j]=j;
			}
			sum=0;
			doo(1<<i);
			if(ans>lss){
	//			cout<<"????";
				okk[i]=1;
			}
		} 
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k+1;j++){
			fa[j]=j;
		}
		sum=0;
		doo(i);//方案 
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
2 1 3 2 4
*/
