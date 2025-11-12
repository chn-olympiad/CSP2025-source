#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,o=0;
	cin>>a>>b>>c;
	for(int i=1;i<a*b;i++){
		cin>>d;
		if(d>c){
			o++;
		}
	}
	cout<<o/a+1<<" ";
	if((o/a+1)%2==1){
		cout<<o%a+1;
	}else{
		cout<<a-o%a;
	}
	return 0;
}
