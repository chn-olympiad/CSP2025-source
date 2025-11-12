#include<bits/stdc++.h>
using namespace std;
int a,b,c[10000009],s,f=0,q=100000;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
		q=min(q,c[i]);
		f=max(f,c[i]);
		s=c[1];
	}
	if(s==f){
		cout<<1<<' '<<1;
	}else{
		cout<<a<<' '<<b;
	}
	return 0;
}
