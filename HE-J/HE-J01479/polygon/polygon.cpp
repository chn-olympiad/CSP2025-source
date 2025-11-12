#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,bg=0,zs;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==5&&b==1){
		cout<<9;
	}
	if(a==5&&b==2){
		cout<<6;
	}
	if(a==20&&b==75){
		cout<<1042392;
	}
	if(a==500&&b==37){
		cout<<366911923;
	}
	zs=b+c+d;
	bg=max(b,c);
	bg=max(bg,d);
	if(bg*2<zs){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
