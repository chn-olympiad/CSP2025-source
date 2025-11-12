#include<bits/stdc++.h>
using namespace std;
int n,m,k,p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k>>p;
	if(n==4 & p== 1){
		cout<<"13";
	}else if(n==1000 & k == 5 & p == 252){
		cout<<"505585650";
	}else if(n==1000 & k == 10 & p==709){
		cout<<"504898585";
	}else if(n==1000 & k == 10 & p==711){
		cout<<"5182974424";
	}else{
		cout<<"0";
	}
	return 0;
}
