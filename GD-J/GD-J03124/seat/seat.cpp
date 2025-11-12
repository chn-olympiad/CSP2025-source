#include<bits/stdc++.h>
#define LL long long
#define itn long long 
using namespace std;
int n, m;
int a[105], temp;
int ans[15][15];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) temp=a[i];
	}
	sort(a+1,a+1+n*m);
	if(m%2==0){
		for(int i=1;i<=m/2;i++){
			for(int j=1;j<=n;j++){
				ans[j][i*2]=a[i]
			}
		}
	}
	for(itn i=1;i<=) 
	return 0;
}

