#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[5005];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	sort(b+0,b+a);
	if(b[0]+b[1]+b[2]>2*b[2])cout<<1;
	else cout<<0;
	return 0;
}
