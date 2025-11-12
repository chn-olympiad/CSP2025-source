#include<bits/stdc++.h>
using namespace std;
int const N=1e8+10;

int n,k,ans,xd=0;
int a[500005],num[500005]={},zt[500005]={};
bool pd=0;

//bool  cmp(){
//	return ;
//}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	if(num[1]==n&&k==0){
		cout<<n;
	}else{
		for(int l=1;l<=n;l++){
			int r;
			for( int s=0; s<=n-l ; s++ ){
				r=l+s;
				ans=a[l];
				for(int x=l+1;x<=r;x++){
					ans^=a[x];
				}
				if(ans==k){
					for(int x=l;x<=r;x++){
						if(zt[x]==1){
							pd=1;
						}else{
							zt[x]=1;
						}
					}
					if(pd==0){
//						cout<<ans<<'\n';
//						cout<<l<<": "<<a[l]<<'\n';
//						cout<<r<<": "<<a[r]<<'\n'<<'\n';
						xd++;
					}
					pd=0;
					break;
				}
			}
		}
		cout<<xd;
	}
	return 0;
}