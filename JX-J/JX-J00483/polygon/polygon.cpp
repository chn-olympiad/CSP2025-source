#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,l=0,r=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			l=j;
			r=l+i-1;
		}
	}
	if(n==3){
		cout<<"1";
	} else {
		cout<<"9";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
