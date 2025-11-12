#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a,c=1,r=1;
void move(){
	if(r==m&&c%2==1||r==1&&c%2==0) c++;
	else if(c%2==1) r++;
	else r--;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;++i){
		cin>>a1;
		if(a1>a) move();
	}
	cout<<c<<' '<<r;
	fclose(stdin);fclose(stdout);
	return 0;
}
