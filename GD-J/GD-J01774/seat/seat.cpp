#include<iostream>
#include<cstdio>
using namespace std;
int a[105]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b;
	cin>>b;
	for(int i=1;i<=n*m-1;i++){
		int c;
		cin>>c;
		a[c]++;
	}
	long long sum=0;
	for(int i=100;i>b;i--){
		if(a[i]!=0)sum+=a[i];
	}
	sum++;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==sum)cout<<i<<" "<<j;
			}
		}
		else if(i%2==0){
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==sum)cout<<i<<" "<<n-j+1;
			}
		}
	}
	return 0;
}
