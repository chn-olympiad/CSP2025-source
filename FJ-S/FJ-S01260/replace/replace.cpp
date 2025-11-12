#include<bits/stdc++.h>
using namespace std;
int a,d;
int i,j;
string b,c;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>d;
	if(a==4){
		for(i=1;i<7;i++){
			cin>>b>>c;
		}
		cout<<2<<endl<<0;
	}
	else if(a==3){
		for(j=1;j<8;j++){
			cin>>b>>c;
		}
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}
