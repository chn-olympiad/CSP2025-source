#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long num=0;
	sort(a,a+n);
	int sum=0;
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			for(long long k=j;k<n;k++){
				num+=a[k];
				if(num>2*a[k]){
					sum++;
				}
			}
			num=0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
