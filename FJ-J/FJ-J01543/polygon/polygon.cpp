#include <bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
int k[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			k[j]=j;
		}
		while(true){
			long long t=0,maxx=-999999999999999999;
			for(int j=1;j<=i;j++){
				if(a[k[j]]>maxx) maxx=a[k[j]];
				t+=a[k[j]];
			}
			if(t>maxx*2) cnt++;
			if(k[1]>=n-i+1) break;
			k[i]++;
			for(int j=i;j>=1;j--){
				if(k[j]>n-i+j){
					k[j-1]++;
					for(int s=j;s<=i;s++){
						k[s]=k[s-1]+1;
					}
				}
			}
		}
	}
	cout << cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
