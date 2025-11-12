#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[1000];
	cin>>a;
	for(int i=1;i<=a;i++)cin>>b[i];
	if(a<3){
		cout<<0;
		return 0;
	}
	sort(b+1,b+a+1);
	if(a==3){
		if(b[1]+b[2]<=b[3]) cout<<0;
		else cout<<1;
	}
	return 0;
}
