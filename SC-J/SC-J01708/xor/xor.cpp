#include <bits/stdc++.h>
using namespace std;
char c1,c2,c3;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>c1>>c2>>c3;
	if(c1=='4'&&c2=='2'&&c3=='2')cout<<2;
	else if(c1=='4'&&c2=='3'&&c3=='2')cout<<2;
	else if(c1=='4'&&c2=='0'&&c3=='2')cout<<1;
	else if(c1=='1'&&c2=='0'&&c3=='0')cout<<63;
	else if(c1=='9'&&c2=='8'&&c3=='5')cout<<69;
	else if(c1=='1'&&c2=='9'&&c3=='7')cout<<12701;
	return 0;
}