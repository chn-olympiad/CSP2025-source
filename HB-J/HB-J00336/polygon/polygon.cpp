#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long cnt=0;
	int b[510];
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(2*max(max(b[i],b[i+1]),max(b[i],b[i+2]))<b[i]+b[i+1]+b[i+2]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
