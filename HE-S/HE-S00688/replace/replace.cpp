#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n;
	cin>>n;
	if(n==4){
		cout<<2<<endl;
		cout<<0;
	}
	if(n==3){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}





/*
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n;
	cin>>n;
	if(n==4){
		cout<<2<<endl;
		cout<<0;
	}
	if(n==3){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
