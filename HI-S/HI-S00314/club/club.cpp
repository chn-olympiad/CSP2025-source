#include <bits/stdc++.h>
using namespace std;
long long a[10000][4];
long long num[4],sum[4],y[10000],f[10000],w[10000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	long long n,t;
	cin>>t;
	for (int l=1;l<=t;l++){
	int c=0;
	cin>>n;
	for (long long z=0;z<=n;z++){
		y[z]=0;
		f[z]=0;
		w[z]=0;
	}
	for (long long i=1;i<=n;i++){
		
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2] &&a[i][1]>=a[i][3] ){
			num[1]++;
			y[i]=a[i][1];
		}
		else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3] ){
			num[2]++;
			f[i]=a[i][2];
		}
		else if(a[i][3]>=a[i][2] && a[i][3]>=a[i][1] ){
			num[3]++;
			w[i]=a[i][3];
		}
		}
		sort(y,y+n+1);
		sort(f,f+n+1);
		sort(w,w+n+1);
		for (int u=1;u<=n/2;u++){
			c+=y[n-u+1];
			c+=f[n-u+1];
			c+=w[n-u+1];
		}
	sum[l]=c;
}
	for (int j=1;j<=3;j++){
		cout<<sum[j]<<' ';
	}
	return 0;
}

