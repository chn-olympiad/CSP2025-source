#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;

if(n>3){
int g[n],p=0;
for(int i=0;i<n;i++){
	cin>>g[i];
	if(g[i]==1){
	p++;
	}
}cout<<p-2;
return 0;
}if(n<3){
	cout<<0;
}else if(n=3){
	cout<<1;
}
	return 0;
}
