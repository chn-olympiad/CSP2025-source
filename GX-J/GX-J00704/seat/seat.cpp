#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen<"number.in","t",stdin>;
	freopen<"number.out","w",stdout>;
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(c>d){
		if(c>e){
			if(c>f){
			cout<<1 1;
			}
		}	else{
				cout<<2 2;
			}
	}	else{
			if(c>f){
				cout<<2 1;
			}
		}
	else{
		if(c>e){
			if(c>f){
				cout<<1 2;
			}
		}
	}	else{
			if(c>f){
				cout1 2;
			}
		}	else{
				cout<<2 2;
			}
	return 0;
}
