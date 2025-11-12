#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,zh=0,max=0,shu=0;
	int ans=0;
	int m=3;
	cin<<n;
	if(n<3||n>5000){
		return 0;
	}
	int mg[n];
	for(int i=1;i<=n;i++){
		cin>>mg[i];
	}
	while(m!=n+1){
		for(int i=1;i<=n;i++){
			shu+=mg[i];
			m--;
			if(max<mg[i]){
				max=mg[i];
			}
			if(shu>2*max)ans++;
		}
	}
	cout<<ans;
	return 0;
}
