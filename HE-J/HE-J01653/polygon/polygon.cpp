#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,bt=0,gun[101010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gun[i];
	}
	for(int i=1;i<=n;i++){
		bt=max(bt,gun[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(gun[i]+gun[j]+gun[k]>bt){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
