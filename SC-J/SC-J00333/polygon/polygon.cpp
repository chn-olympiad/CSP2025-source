#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
int he(int star,int en){
	int tt=0;
	for(int i=star;i<=en;i++){
		tt+=a[i];
	}
	return tt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long z=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int k=3;k<=n;k++){
		for(int j=1;j<=n-k+1;j++){
			for(int i=j+k-1;i<=n;i++){
				if(he(j,k)>a[i]*2){
					z++;
				}
			}
		}		
	}
	cout<<z;
	return 0;
} 