#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int ysdufg=1;ysdufg<=t;ysdufg++){
		int n,s=0,g,qw=0;
		cin>>n;
		int a[1001],b[1001],c[1001],d[1001],e[1001],f[1001];
		int a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&b[i]>=c[i]){
				a1++;
				d[a1]=a[i];
			}
			if(a[i]>=c[i]&&c[i]>=b[i]){
				a1++;
				d[a1]=a[i];
			}
			if(b[i]>=a[i]&&a[i]>=c[i]){
				a2++;
				e[a2]=b[i];
			}
			if(b[i]>=c[i]&&c[i]>=a[i]){
				a2++;
				e[a2]=b[i];
			}
			if(c[i]>=b[i]&&b[i]>=a[i]){
				a3++;
				f[a3]=c[i];
			}
			if(c[i]>=a[i]&&a[i]>=b[i]){
				a3++;
				f[a3]=c[i];
			}
		}
		sort(d+1,d+a1+1);
		sort(e+1,e+a2+1);
		sort(f+1,f+a3+1);
		for(int i=n;i>=n/2;i--){
			qw+=d[i];
			qw+=e[i];
			qw+=f[i];
		}
		cout<<qw<<endl;
	}
	return 0;
}

