#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10000];
long long sm1,sm2,sm3,sm4,sm5;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				sm1=a[i]+a[j]+a[k];
				if(sm1>2*a[k]){
					cnt++;
				}
				if(a[k+1]!=0){
					sm2=sm1+a[k+1];
					if(sm2>2*a[k+1]){
						cnt++;
					}
				}
				if(a[k+2]!=0){
					sm3=sm2+a[k+2];
					if(sm3>2*a[k+2]){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
