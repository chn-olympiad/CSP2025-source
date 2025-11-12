#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1001][1001],ans=0,lans=0,b[1001];
int fb(int m){
	int biggest=a[m][1],wz=1;
	for(int i=2;i<=n;i++){
		if(a[m][i]>biggest){
			biggest=a[m][i];
			wz=i;
		}
	}a[m][wz]=-1000;
	return biggest;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		int m=n/2;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=m;k++){
				int an=fb(j);
				lans+=an;
				b[j]=lans;
			}
		}sort(b,b+n);
		ans+=b[1];
		cout<<ans;
	}
	return 0;
}
