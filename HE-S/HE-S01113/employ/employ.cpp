#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b,c[10000],d[10000],v=0,p=0,m;
	cin>>a>>b;
	char z;
	for(int i=0;i<a;i++){
		cin>>z;
		c[i]=z-48;
		if(z-48==1){
			v++;
			if(v==1){
				m=i;
			}
		}
	}
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
	if(v<b){
		cout<<0;
		return 0;
	}
	else if(b==1&&v>=1){
		for(int i=0;i<a;i++){
			if(d[i]>m){
				p++;
			}
		}
	}
	cout<<p;
	return 0;
}
