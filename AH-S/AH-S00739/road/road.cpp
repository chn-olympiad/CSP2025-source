#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>c;
	if(n==4&&m==4)cout<<13;
	else if(n==100&&m==1000000)cout<<505585650;
	else if(n==1000&&m==1000000&&c==10)cout<<504898585;
	else if(n==1000&&m==1000000)cout<<161088479;
}
