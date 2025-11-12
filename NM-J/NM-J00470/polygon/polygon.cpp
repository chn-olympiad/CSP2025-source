#include<bits/stdc++.h>
using namespace std;
int n,m=0,a[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]+a[j+1]+a[j+2]>2*a[j+2]){
				m++;
				}
	}
	}
	cout<<m;
	return 0;
}
