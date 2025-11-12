#include <bits/stdc++.h>
using namespace std;
long long n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long a[100001][6]={0},x[100001]={0},y[100001]={0},z[100001]={0},l=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		long long e[4]={0},maxn=-2e9,m,minn=-2e9,s,o=-2e9,b;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(a[j][k]>=maxn){
					maxn=a[j][k];
					m=k;
					x[j]=maxn;
				}else if(a[j][k]>=minn){
					minn=a[j][k];
					s=k;
					y[j]=minn;
				}else{
					o=a[j][k];
					b=k;
					z[j]=o;
				}
			}
			if(e[m]<n/2)e[m]++;
			else if(e[s]<n/2)e[s]++;
			else e[b]++;
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		sort(z+1,z+n+1);
		for(int j=n;j>=1;j--){
			if(j>=n-e[m]){
				l+=x[j];
			}else if(j>=n-e[m]-e[s]){
				l+=y[j];
			}else{
				l+=z[j];
			}
		}
		cout<<l<<endl;
	}
	return 0;
}
