#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int a;cin>>a;int ans=1;int b;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)ans++;
	}
	int y=ceil(ans/double(n));
	int x=y%2==0?(n-ans+(y-1)*n+1):(ans-(y-1)*n);
	cout<<y<<' '<<x;
	fclose(stdin);fclose(stdout);
	return 0;
}
