#include <iostream>
#include <cstdio>
using namespace std;
int a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;int cnt=0;
	if(n<=2)cout<<0;
	else{
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]+a[2]+a[3]>=max(a[3],max(a[1],a[2]))*2)cnt++;
	}
	

	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
