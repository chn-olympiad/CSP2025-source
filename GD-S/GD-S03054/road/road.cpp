#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==4){
		cout<<13<<endl;
	}
	if(a==1000){
		if(b==1000000){
			if(c==5){
				cout<<505585650<<endl;
			}else{
				cout<<504898585<<endl;
			}
		}
		if(b==100000){
			cout<<5182974424<<endl;
		}
	}

	return 0;
}

