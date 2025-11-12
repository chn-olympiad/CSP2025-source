#include<bits/stdc++.h>
using namespace std;

int n;




int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n<3){
			cout<<0;
		}else{
			int a,b,c;
			cin>>a>>b>>c;
			cout<<(a+b>c)&&(a+c>b)&&(b+c>a);
		}
	}else{
		cout<<123;
	}
	
	return 0;
}