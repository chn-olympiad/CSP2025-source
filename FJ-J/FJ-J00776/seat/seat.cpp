#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)cnt++;
	}
	int x=cnt/n+1;
	int y=cnt/n%2==0?cnt%n+1:n-cnt%n;
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
