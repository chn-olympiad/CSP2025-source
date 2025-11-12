#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10005][10005],b[10005];
long long maxn=-1,s=-1,c[5],sum=0,m=-1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			c[i]=0;
		}
		for(long long i=1;i<=n;i++){
			for(long long k=1;k<=3;k++){
				cin>>a[i][k];
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long k=1;k<=3;k++){
				if(a[i][k]>maxn){
					maxn=a[i][k];
					s=k;
				}
			}
			sum+=maxn;
			c[s]++;
			maxn=0;
			s=0;
		}
		m=2/n;
		if(c[1]<=m&&c[2]<=m&&c[3]<=m){
			cout<<sum;
		}
		sum=-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
