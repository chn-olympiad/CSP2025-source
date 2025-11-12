#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
using namespace std;

struct fx{
	int z,id;
}x[600001];
struct fsum{
	int z,pl;
}sm[600001];
int n,k,a[600002],dp[600002],mt[600002],amt[600002],sum[600002];
bool cmpx(fx x,fx y){
	if(x.z==y.z){
		return x.id<y.id;
	}
	return x.z<y.z;
}
bool cmpsum(fsum x,fsum y){
	if(x.z==y.z){
		return x.pl<y.pl;
	}
	return x.z<y.z;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor6.in","r",stdin);
//	freopen("xor5.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]^a[i]);
		x[i].id=i,x[i].z=(sum[i-1]^k);
		sm[i].pl=i,sm[i].z=sum[i];
//		cout<<x[i].z<<" "<<sum[i]<<"\n";
	}
	for(int i=1;i<=n;i++)amt[i]=n+1;
	sort(x+1,x+n+1,cmpx);
	sort(sm+1,sm+n+1,cmpsum);
	int pl=1;
//	for(int i=1;i<=n;i++){
//		cout<<"smi.pl:"<<sm[i].pl<<" smi.z:"<<sm[i].z<<"\n";
//	}
//	for(int i=1;i<=n;i++){
//		cout<<"xi.id:"<<x[i].id<<" xi.z:"<<x[i].z<<"\n";
//	}
	for(int i=1;i<=n;i++){
		while(pl<n&&sm[pl].z<x[i].z)pl++;
		if(sm[pl].z>x[i].z||sm[pl].z<x[i].z)continue;
		while(pl<n&&sm[pl].pl<x[i].id&&sm[pl].z<=x[i].z)pl++;
		if(sm[pl].z>x[i].z||sm[pl].z<x[i].z)continue;
//		cout<<"PL:"<<pl<<" I:"<<i<<"\n";
//		cout<<"smpl.pl:"<<sm[pl].pl<<" smpl.z:"<<sm[pl].z<<"\n";
//		cout<<"x.id:"<<x[i].id<<" x.z:"<<x[i].z<<"\n";
		if(sm[pl].pl>=x[i].id)amt[x[i].id]=sm[pl].pl;
	}
//	for(int i=1;i<=n;i++)cout<<amt[i]<<" ";
//	cout<<"\n";
	int mxas=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
		dp[amt[i]+1]=max(dp[amt[i]+1],dp[i]+1);
//		cout<<dp[i]<<" "<<amt[i]<<"\n";
		mxas=max(mxas,dp[i]);
	}
	mxas=max(mxas,dp[n+1]);
	cout<<mxas;
	akioi;
}
/*
8 2
0 2 1 2 2 1 2 2 

4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

10 2
0 8 0 6 0 3 3 3 0 2
*/
//void pushup(int u){tr[u].mr=min(tr[u*2].mr,tr[u*2+1].mr);}
//void pushdown(int u){
//	tr[u*2].mr=min(tr[u*2].mr,tr[u].lz);
//	tr[u*2+1].mr=min(tr[u*2+1].mr,tr[u].lz);
//	tr[u*2].lz=min(tr[u*2].lz,tr[u].lz);
//	tr[u*2+1].lz=min(tr[u*2+1].lz,tr[u].lz);
//}
//void build(int u,int l,int r){
//	if(l==r){
//		tr[u].mr=n+1;
//	}else{
//		int mid=(l+r)/2;
//		build(u*2,l,mid);
//		build(u*2+1,mid+1,r);
//		pushup(u);
//	}
//}
//void modify(int u,int l,int r,int ll,int rr,int z){
//	if(ll>=l&&rr<=r){
//		tr[u].mr=min(tr[u].mz,z);
//		tr[u].lz=min(tr[u].lz,z);
//	}else{
//		int mid=(ll+rr)/2;
//		pushdown(u);
//		if(l<=mid)modify(u*2,l,r,ll,mid,z);
//		if(r>mid)modify(u*2+1,l,r,mid+1,rr,z);
//		pushup(u);
//	}
//}
//int query(int u,int pl,int ll,int rr){
//	if(ll==rr){
//		return tr[u].mr;
//	}else{
//		int mid=(ll+rr)/2;
//		pushdown(u);
//		if(pl<=mid)return query(u*2,pl,ll,mid);
//		else return query(u*2+1,pl,mid+1,rr);
//		pushup(u);
//	}
//}
//	for(int i=0;i<=19;i++){
//		for(int j=1;j<=n;j++){
//			nxt[j][i]=n+1;
//		}
//	}
//	for(int i=0;i<=19;i++){
//		int lst1=0;
//		for(int j=1;j<=n;j++){
//			sum[j][i]=sum[j][i-1];
//			if((a[j]&(1<<i))!=0){
//				sum[j][i]++;
//				nxt[lst1][i]=j;
//				lst1=j;
//			}
//		}
//	}
//	for(int i=0;i<=19;i++){
//		if((k&(1<<i))!=0){
//			for(int j=1;j<=n;j++)mt[j]=n+1;
//			int lst=0;
//			for(int j=1;j<=n;j++){
//				if((a[j]&(1<<i))!=0){
//					for(int l=lst+1;l<=j;l++){
//						mt[l]=j;
//					}
//					lst=j;
//				}
//			}
////			cout<<"I:"<<i<<" (1<<i):"<<(1<<i)<<"\n";
////			for(int j=1;j<=n;j++){
////				cout<<mt[j]<<" ";
////			}
////			cout<<"\n";
//			for(int j=1;j<=n;j++)amt[j]=max(amt[j],mt[j]);
//		}
//	}
//	for(int i=0;i<=19;i++){
//		if((k&(1<<i))==0){
//			for(int j=1;j<=n;j++)mt[j]=n+1;
//			int lst=0,lst2=0;
//			for(int j=1;j<=n;j++){
//				if((a[j]&(1<<i))==0){
//					mt[j]=j;
//				}else{
//					for(int l=lst+1;l<=j;l++){
//						if(amt[l]>=j)mt[l]=n+1;
//					}
//					mt[lst]=j;
//					for(int l=lst2+1;l<=lst;l++){
//						if(amt[l]>=lst)mt[l]=j;
//					}
//					lst2=lst;
//					lst=j;
//				}
//			}
////			cout<<"I:"<<i<<" (1<<i):"<<(1<<i)<<"\n";
////			for(int j=1;j<=n;j++){
////				cout<<mt[j]<<" ";
////			}
////			cout<<"\n";
//			for(int j=1;j<=n;j++)amt[j]=max(amt[j],mt[j]);
//		}
//	}
