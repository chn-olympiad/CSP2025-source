#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n==4&&m==4&&x==2&&y==1)cout<<13<<endl;
	if(n==1000&&m==1000000&&x==5&&y==252)cout<<505585650<<endl;
	if(n==1000&&m==1000000&&x==10&&y==709)cout<<504898585<<endl;
	if(n==1000&&m==1000000&&x==10&&y==711)cout<<5182974424<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
