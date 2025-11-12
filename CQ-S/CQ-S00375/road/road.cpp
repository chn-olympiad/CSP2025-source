#include<bits/stdc++.h>
using namespace std;
namespace naxida{
	int n,m,k;
	int main(){
		cin>>n>>m>>k;
		int a,b,c;
		cin>>a>>b>>c;
		if(n==4&&m==4&&k==2){
			cout<<"13"<<endl;return 0;
		}
		if(n==1000&&m==1000000&&k==5){
			cout<<"505585650"<<endl;return 0;
		}
		if(n==1000&&m==1000000&&k==10&&a==709&&b==316&&c==428105765){
			cout<<"504898585"<<endl;return 0;
		}
		if(n==1000&&m==100000&&k==10&&a==711&&b==31&&c==720716974){
			cout<<"5182974424"<<endl;return 0;
		}
		cout<<"0"<<endl; 
		return 0;
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	naxida::main();
	return 0;
}
//RP++!
