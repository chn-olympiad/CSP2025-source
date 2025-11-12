#include<bits/stdc++.h>
using namespace std;
int b[100],n,m,a1,num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;++i){
		cin>>b[i];
		if(b[1]<b[i])++num;
	}
	int c=(num-1)%n+1,r=(num-1)/n+1;
	if(r%2==0)c=n-c+1;
	cout<<r<<' '<<c<<endl;
	return 0;
}
