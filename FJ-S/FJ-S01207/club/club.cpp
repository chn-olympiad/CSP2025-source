#include<bits/stdc++.h>
using namespace std;
struct sss{
	int v,w;
}a[100001],b[100001],c[100001];
bool cmp(sss x,sss y){
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].w>>b[i].w>>c[i].w;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int l1=1,t1=0,l2=1,t2=0,l3=1,t3=0,n1=n,sum=0;
		while(n1--){
			if(a[l1].w>=b[l2].w&&a[l1].w>=c[l3].w&&t1<m){
				sum+=a[l1].w;t1++;l1++;
			}else if(b[l2].w>=a[l1].w&&b[l2].w>=c[l3].w&&t2<m){
				sum+=b[l2].w;t2++;l2++;
			}else{
				sum+=c[l3].w;t3++;l3++;
			}
		}
		cout<<sum;
	}
	return 0;
}
/*

*/
