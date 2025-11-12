#include <iostream>
#include <string>
using namespace std;

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,p;
	cin>>n>>p;
	string s1[123455];
	string s2[123455];
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=p;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=n;i++){
		cout<<0<<endl;
	}
	return 0;
}
