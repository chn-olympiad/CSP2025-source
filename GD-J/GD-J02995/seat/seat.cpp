#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr,sum=0,yu,shang;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		if(i==0){
			cin>>xr;
			continue;
		}
		int j;
		cin>>j;
		if(j>xr){
			sum++;
		}
	}
	yu=sum/n+1;
	shang=sum%n;
	if(yu%2==1){
		cout<<yu<<" "<<shang+1;
	}else{
		cout<<yu<<" "<<n-shang;
	}
	
	return 0;
}
