#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],xx[500005],c[500005],d[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xx[i]=xx[i-1]^a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int l=1;l+i-1<=n;l++){
			int r=l+i-1;
//			cout<<l<<" "<<r<<" "<<d[r]<<" "<<d[l-1]<<endl;
			if((xx[r]^xx[l-1])==k&&d[r]-d[l-1]==0){
				cnt++;
				for(int j=l;j<=r;j++) c[j]++;
				for(int j=1;j<=n;j++){
					d[j]=d[j-1];
					if(c[j]) d[j]++;
				}
				l=r;
			}
		} 
	}
	cout<<cnt;
	return 0;
}
