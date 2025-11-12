#include<bits/stdc++.h>
using namespace std;

long long n,a[1000010],cnt;
int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(j-i>=2){
				long long he=0,b=0;
				for(int k=i;k<=j;k++){
					he+=a[k];
					b=max(b,a[k]);
			    }
			    if(b*2<he){
					cnt++;
					cnt=cnt%998244353;
				}
			}
		}
	}
	cout<<cnt;

    return 0;
}
