#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[1100000],c[1100000],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=i;j<=n;j++){
			long long q=sum^a[j];
			if(q>m){
				break;
			}
			sum=sum^a[j];
			if(sum==m){
				b[++k]=i;
				c[k]=j;
				break;
			}
		}
	}
	for(int i=1;i<=k-1;i++){
		for(int j=1;j<=k-1-i;j++){
			if(c[j]>c[j+1]){
				swap(b[j],b[j+1]);
				swap(c[j],c[j+1]);
			}
		}
	}
	int i=1,sum=0,end=0;
	while(i<=k){
		if(b[i]>end){
			sum++;
			end=c[i];
		}
		i++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
