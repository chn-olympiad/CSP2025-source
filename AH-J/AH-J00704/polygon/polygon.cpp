#include<bits/stdc++.h>
using namespace std;
int n,a[4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<(n<3?0:((a[1]+a[2]>2*a[3])||(a[1]+a[3]>2*a[2])||(a[2]+a[3]>2*a[1])?1:0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
