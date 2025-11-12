#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
struct KKK{
	int id,mxd;
	ll mx;
}T[N];
void fil(int p,int id_,int mxd_,ll mx_){
	T[p].id=id_;
	T[p].mxd=mxd_;
	T[p].mx=mx_;
}
bool cmp(KKK x,KKK y){
	return x.mx>y.mx;
}
int tot[5],K[5][N];
ll A[N][5],B[N];
void clr(){
	memset(A,0,sizeof(A));
	memset(T,0,sizeof(T));
	memset(tot,0,sizeof(tot));
	memset(B,0x3f,sizeof(B));
	memset(K,0,sizeof(K));
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){		
		clr();
		int n,P;
		ll x,y,z,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			A[i][1]=x;	A[i][2]=y;	A[i][3]=z;
			if(x>=y&&x>=z)		fil(i,i,1,x);
			else if(y>=x&&y>=z)	fil(i,i,2,y);
			else				fil(i,i,3,z);
		}
		sort(T+1,T+1+n,cmp);
		for(int i=1;i<=n;i++){
			K[T[i].mxd][++tot[T[i].mxd]]=T[i].id;
			ans+=T[i].mx;
		}
		bool tf=1;
		for(int i=1;i<=3;i++){
			if(tot[i]>n/2){
				P=i;
				tf=0;
			}
		}
		if(tf){
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=tot[P];i++){
			for(int j=1;j<=3;j++)	
				if(j!=P)
					B[i]=min(B[i],abs(A[K[P][i]][j]-A[K[P][i]][P]));
		}
		sort(B+1,B+1+tot[P]);
		for(int i=1;i<=tot[P]-n/2;i++)
			ans-=B[i];
		printf("%lld\n",ans);
	}
	return 0;
}
