#include<bits/stdc++.h>
using namespace std;
int a,c[1000005],d;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int z=0;z<b.size();z++){
		if(b[z]>='0' and b[z]<='9')c[d++]=int(b[z]-48);
	}
	sort(c,c+d);
	for(int z=d-1;z>=0;z--){
		cout<<c[z];
	}
	return 0;
}
