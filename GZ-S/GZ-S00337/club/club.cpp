//GZ-00337 贵阳市中天中学 王禹梓晨
#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
int t,n,a[N][10],b[10],sum[10],maxn;
int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int ab=1;ab<=t;ab++){
		cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		maxn=max(a[i][1],a[i][2]);
		maxn=max(maxn,a[i][3]);
		for(int j=1;j<=3;j++){
			if(a[i][j]==maxn&&b[j]<n/2+1){
				b[j]++;
				sum[ab]+=maxn;
			}else{
				sum[ab]+=0;
			}
		}
	}
}
	for(int i=0;i<t;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}
