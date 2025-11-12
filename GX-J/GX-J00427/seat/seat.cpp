#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long n,m,b;
long long a[1000000],c[150][150]={0};
long long cnt=1,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];b=a[1];
	for(long long i=2;i<=n*m;i++)cin>>a[i];
	for(long long i=1;i<=n*m;i++){
		for(long long j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			c[i][j]=a[cnt];
			cnt++;
		}
		i++;
		for(long long j=n;j>=1;j--){
			c[i][j]=a[cnt];
			cnt++;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			if(c[i][j]==b){
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
