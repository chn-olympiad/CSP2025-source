#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ff{
	long long int x,y;
	long long int pd;
	long long int sum;
}a[4000005];
struct hh{
	int c;
	int yl;
}cc[15];
int op[15][2000000];
long long int xza;
bool xzaa[20];
bool pp(ff x,ff y){
	if(x.sum<=y.sum)return 1;
	return 0;
}
bool oo(hh x,hh y){
	if(x.c>=y.c)return 1;
	return 0;
}
//int cc[15][2000000];
long long int sum2[15];
long long int c[15];
bool use[15];
long long int t;long long int n,m,k;
long long int ans;
long long int f[4000000];
long long int daan=9000000000;
		long long int jd=0;long long int num;
long long int fa(long long int x){
	if(f[x]==x){
		return x;
	}
	f[x]=fa(f[x]);
	return f[x];
}
void fz(long long int x){
	f[f[x]]=x;
	f[x]=x;
}
void zxscs(long long int o){
	long long int x,y;
	
	for(long long int i=1;i<=t;i++){
		if(a[i].pd==1){
			if(use[a[i].y-n]==0){
				continue;
			}
		}
		x=a[i].x;y=a[i].y;
		if(fa(x)==fa(y)){
			continue;
		}
		else{
			fz(x);
			f[x]=f[y];
			num+=a[i].sum;
			o--;
			if(o==0){
				return ;
			}
	}
}
return;

}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
		cin>>n>>m>>k;
		sum2[0]=1;
		for(long long int i=1;i<=k;i++){
			sum2[i]=sum2[i-1]*2;
		}
		long long int x,y,z;
		for(long long int i=1;i<=m;i++){
			cin>>x>>y>>z;
			a[i].sum=z;a[i].x=x;a[i].y=y;
		}
		t=m;
		for(long long int i=1;i<=k;i++){
			cin>>cc[i].c;cc[i].yl=i;
			for(long long int j=1;j<=n;j++){
				cin>>op[i][j];
			}
		}
		sort(cc+1,cc+k+1,oo);
		for(long long int i=1;i<=k;i++){
			c[i]=cc[i].c;
			for(long long int j=1;j<=n;j++){
				t++;
				a[t].sum=op[cc[i].yl][j];
				a[t].x=j;a[t].y=n+i;a[t].pd=1;
			}
		}
		sort(a+1,a+t+1,pp);
		
		for(long long int i=1;i<=k;i++){
				use[i]=1;
				num+=c[i];
				jd++;
			}
			for(long long int i=1;i<=n+k;i++){
				f[i]=i;
			}	
			zxscs(n+jd);
			ans=num;
		
		for(long long int l=1;l<=k;l++){
			jd=0;num=0;use[l]=0;
			for(int i=1;i<=k;i++){
				num+=c[i]*use[i];
				jd++;
			}
			for(long long int i=1;i<=n+k;i++){
				f[i]=i;
			}
			zxscs(n+jd);
			if(num<ans){
				ans=num;
			}
			else{
				use[l]=1;
			}
			daan=min(daan,ans);
		}
		cout<<daan;
		return 0;
		//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//struct ff{
//	long long int x,y;
//	long long int pd;
//	long long int sum;
//}a[4000005];
//long long int xza;
//bool xzaa[20];
//bool pp(ff x,ff y){
//	if(x.sum<=y.sum)return 1;
//	return 0;
//}
//long long int sum2[15];
//long long int c[15];
//bool use[15];
//long long int t;long long int n,m,k;
//long long int ans[10000];
//long long int f[4000000];
//long long int fa(long long int x){
//	if(f[x]==x){
//		return x;
//	}
//	f[x]=fa(f[x]);
//	return f[x];
//}
//void fz(long long int x){
//	f[f[x]]=x;
//	f[x]=x;
//}
//void zxscs(long long int l,long long int o){
//	long long int x,y;
//	
//	for(long long int i=1;i<=t;i++){
//		if(a[i].pd==1){
//			if(use[a[i].y-n]==0){
//				continue;
//			}
//		}
//		x=a[i].x;y=a[i].y;
//		if(fa(x)==fa(y)){
//			continue;
//		}
//		else{
//			fz(x);
//			f[x]=f[y];
//			ans[l]+=a[i].sum;
//			o--;
//			if(o==0){
//				return ;
//			}
//	}
//}
//return;
//
//}
//int main(){
//	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
//		
//		cin>>n>>m>>k;
//		sum2[0]=1;
//		for(long long int i=1;i<=k;i++){
//			sum2[i]=sum2[i-1]*2;
//		}
//		long long int x,y,z;
//		for(long long int i=1;i<=m;i++){
//			cin>>x>>y>>z;
//			a[i].sum=z;a[i].x=x;a[i].y=y;
//		}
//		t=m;
//		for(long long int i=1;i<=k;i++){
//			cin>>c[i];
//			if(c[i]>0)xza=1;
//			for(long long int j=1;j<=n;j++){
//				t++;
//				cin>>a[t].sum;
//				if(a[t].sum==0)xzaa[i]=1;
//				a[t].x=j;a[t].y=n+i;a[t].pd=1;
//			}
//		}
//		sort(a+1,a+t+1,pp);
//		long long int daan=9000000000;
//		long long int jd=0;long long int num;
//		for(int i=1;i<=k;i++){
//			if(xzaa[i]==0)xza=1;
//		}
//		long long int ggb=0;
//		if(xza==0){
//			ggb=sum2[k]-1;
//		}
//		for(long long int l=ggb;l<sum2[k];l++){
//			jd=0;num=0;
//			for(long long int i=1;i<=k;i++){
//				use[i]=0;
//				if((l&sum2[i-1])>0){
//					num+=c[i];
//					use[i]=1;
//					jd++;
//				}
//			}
//			for(long long int i=1;i<=n+k;i++){
//				f[i]=i;
//			}
//			zxscs(l,n+jd);
//			ans[l]+=num;
//			daan=min(daan,ans[l]);
//		}
//		cout<<daan;
//		
//}
}