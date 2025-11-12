#include<bits/stdc++.h>
using namespace std;
int h,l,a,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>h>>l;
	for(int i=0;i<h;i++){
		cin>>a;
		if(a==l){
			s+=1;
		}
	}
	cout<<s;
	return 0;
}
