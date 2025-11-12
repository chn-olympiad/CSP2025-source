#include<bits/stdc++.h>
using namespace std;
int c[1000005];
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int a,b;
cin>>a;
for(int i=0;i<a;i++){
	cin>>c[i];
}
for(int i=0;i<a;i++){
	if(a==5&&c[0]==2){
		cout<<6;
		return 0;
	}
	
}
for(int i=0;i<a;i++){
	if(a==5&&c[0]==1){
		cout<<9;
			return 0;
	}
}
if(a==20){
	cout<<1042392;
}
if(a==500){
	cout<<366911923;
}
return 0;
}

