#include<bits/stdc++.h>
using namespace std;
long long a[100001][4];
long long fst[100001],sec[100001],tid[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n;
		cin>>n;
		long long max1=n/2;
		long long sum=0;
		for(int j=1;j<=n;j++){
			long long maxn=-1;
			int num=0;
			for(int z=1;z<=3;z++){
				cin>>a[j][z];
				if(a[j][z]>maxn){
					num=z;
				}
				maxn=max(maxn,a[j][z]);		
			}
			sum+=maxn;
		}
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				a[j][z]=0;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
