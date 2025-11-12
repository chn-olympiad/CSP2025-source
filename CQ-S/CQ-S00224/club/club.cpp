#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,ans;
int sum[3];
struct node{
	int x,y,z;
}A[N];
struct Node{
	int a,b,val;
	int id[2],sum[2];
}B[N];
bool cmpa(node X,node Y){
	return X.x==Y.x?X.y==Y.y?X.z<Y.z:X.y<Y.y:X.x<Y.x; 
}
bool cmpb(Node x,Node y){
	int cntx,cnty;
	if((x.sum[0]==1&&x.sum[1]==1)||x.sum[1]==2)
		cntx=0;
	if(x.sum[0]==2)
		cntx=2;
	if(x.sum[0]==3)
		cntx=3;
	if((y.sum[0]==1&&y.sum[1]==1)||y.sum[1]==2)
		cnty=0;
	if(y.sum[0]==2)
		cnty=2;
	if(y.sum[0]==3)
		cnty=3;
	if(cntx==cnty)
		return x.val>y.val;
	else
		return cntx<cnty;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>A[i].x>>A[i].y>>A[i].z;
		sort(A+1,A+n+1,cmpa);
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++){
			int a=A[i].x,b=A[i].y,c=A[i].z,ida=0,idb=1,idc=2;
			if(a<b){
				swap(a,b);
				swap(ida,idb);
			}
			if(a<c){
				swap(a,c);
				swap(ida,idc);
			}
			if(b<c){
				swap(b,c);
				swap(idb,idc);
			}
			B[i].a=a;
			B[i].b=b;
			B[i].val=a-b;
			B[i].id[0]=ida;
			B[i].id[1]=idb;
			if(a==c){
				B[i].sum[0]=3;
				B[i].sum[1]=3;
			}
			else if(a==b){
				B[i].sum[0]=2;
				B[i].sum[1]=1;
			}
			else if(b==c){
				B[i].sum[0]=1;
				B[i].sum[1]=2;
			}
			else{
				B[i].sum[0]=1;
				B[i].sum[1]=1;
			}
		}
		sort(B+1,B+n+1,cmpb);
		for(int i=1;i<=n;i++){
			if((B[i].sum[0]==1&&B[i].sum[1]==1)||B[i].sum[0]==2||B[i].sum[1]==2){
				if(sum[B[i].id[0]]<n/2){
					sum[B[i].id[0]]++;
					ans+=B[i].a;
				}
				else{
					sum[B[i].id[1]]++;
					ans+=B[i].b;
				}
			}
			else
				ans+=B[i].a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
