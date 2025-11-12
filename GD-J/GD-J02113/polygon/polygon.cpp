#include<bits/stdc++.h> 
using namespace std;
int b[500005];
int a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	sort(b+1,b+a+1);
	if(b[1]+b[2]>b[3])
		cout<<1;
	else
		cout<<0;
	return 0;
}
