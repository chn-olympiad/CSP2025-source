#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,shuchu,n;
int main(){
	freopen("poygon.in","r",stdin);
	freopen("poygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c;
	if((a+b)>c){
		shuchu++;
	}
	if((c+b)>a){
		shuchu++;
	}
	if((a+c)>b){
		shuchu++;
	}
	cout<<shuchu;
	return 0;
}
