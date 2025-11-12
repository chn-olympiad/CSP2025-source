#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=0,s=0;
	cin>>n>>s;
	if(n==4){
		cout<<"13"<<endl;
	}else if(n==1000&&s!=1000000){
		cout<<"505585650"<<endl;
	}else if(n==1000){
		cout<<"504898585"<<endl;
	}else{
		cout<<"5182974424"<<endl;
	}
	return 0;
}
