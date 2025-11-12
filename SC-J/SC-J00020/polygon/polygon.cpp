#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long q[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long sum=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	q[1]=a[1];
	for(int i=2;i<=n;i++)
	q[i]=q[i-1]+a[i];
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(q[j]-q[i-1]>2*a[j]){
				sum++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
} 