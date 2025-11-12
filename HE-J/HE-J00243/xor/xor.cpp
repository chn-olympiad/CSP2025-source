#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,K=1<<20+10;
//Sparse Table? QZH? dp? O(nlogn)?
int n,k,a[N],qzh[N];
ll f[N];
ll ans;
void pt(int a[],int n){
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
	return;
}
int get_xor(int l,int r){//O(1) query segment xor result
	int ret=qzh[r]^qzh[l-1];
}
void dp(){//O(n2)
	f[0]=0;
	for(int i=1;i<=n+1;i++){
		for(int k=i-1;k>=1;k--){
			f[i-1]=max(f[i-1],f[k]);
		}
		for(int j=i;j<=n;j++){//O(n2)
			if(get_xor(i,j)==k) {
				f[j]=f[i-1]+1;
//				printf("[%d,%d],f[%d]=%d\n",i,j,j,f[j]);
				ans=max(f[j],ans);
				break;
			}
		}
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
//		printf("%d xor %d = %d\n",a[i],qzh[i-1],qzh[i]);
	}
//	pt(a,n);
//	pt(qzh,n);
	dp();
//	pt(f,n);
	return 0;
} 
