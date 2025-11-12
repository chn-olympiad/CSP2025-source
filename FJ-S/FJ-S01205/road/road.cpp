#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum1,sum2,mn=999999;
struct p{
	int u,uu,val;
}a[1000005];
bool cmpp(p c,p d){
	return c.val>d.val;
}
struct xiang{
	int cos[10005],reb;
	long long all;
}b[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].uu>>a[i].val;
		sum1+=a[i].val;
	}
	sort(a+1,a+1+n,cmpp);
	if(m>n-1){
		for(int i=1;i<=m-(n-1);i++){
			sum1-=a[i].val;
		}
	}
	for(int j=1;j<=k;j++){
		cin>>b[j].reb;
		for(int k=1;k<=n;k++){
			cin>>b[j].cos[k];
			b[j].all+=b[j].cos[k];
		}
		mn=min(mn,b[j].all+b[j].reb);
	}
	if(mn<sum1){
		cout<<mn;
	}else{
		cout<<sum1;
	}

	return 0;
}
