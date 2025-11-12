#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a,b,c,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b+c>d&&c+d>b&&b+d>c){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
