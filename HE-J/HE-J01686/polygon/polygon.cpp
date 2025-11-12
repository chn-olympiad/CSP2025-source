#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		int b=a[1]+a[2]+a[3];
		int c=a[3];
		if(b>c*2){
			cout<<1;
			return 0;
		}
		else {
		cout<<0;
		return 0;}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
