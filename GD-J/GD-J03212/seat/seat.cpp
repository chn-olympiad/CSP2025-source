#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long x,y,q,c=0;
	cin>>x>>y;
	int a[x+1][y+1],m[x+1][y+1];
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			cin>>a[i][j];
			if(a[1][1]<a[i][j]) c++;}}
	q=a[1][1];
	cout<<c/x+1<<' ';
	bool flag=(c/x+1)%2;
	long long num=c%x+1;
	if(flag) cout<<num;
	else if(num-x>0) cout<<num-x+1;
	else cout<<num+x-1;
	fclose(stdin);
	fclose(stdout);
}
