#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct qj{
	int s,z;
}q[500005];
bool b[500005];
int ql;
int xr[500005];
int xrlen;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=/*min(1000,*/n;i++){
		cin>>a[i];
		if(a[i]==k){
			q[++ql].s=i;
			q[ql].z=i;
			b[i]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			xrlen=0;
			continue;
		}
		if(xrlen!=0){
			xrlen++;
			xr[xrlen]=(xr[xrlen-1]^a[i]);
			if(xr[xrlen]==k){
//				cout<<xr[xrlen];
				q[++ql].s=i-xrlen+1;
				q[ql].z=i;
				xrlen=0;
				continue;
			}
			for(int j=1;j<xrlen;j++){
				if((xr[xrlen]^xr[j])==k){
//					cout<<i-xrlen+1<<' ';
//					cout<<(xr[xrlen]^xr[j]);
					q[++ql].s=j+1;
					q[ql].z=i;
					xrlen=0;
					break;
				}
			}
		}else{
			xrlen++;
			xr[xrlen]=a[i];
		}
	}
/*	for(int i=1;i<=ql;i++){
		cout<<q[i].s<<' '<<q[i].z<<endl;
		int nxor=0;
		for(int j=q[i].s;j<=q[i].z;j++){
			nxor^=a[j];
		}
		cout<<nxor<<endl;
		if(nxor!=k){
			break;
		}
	}
*/	cout<<ql;
	return 0;
}

