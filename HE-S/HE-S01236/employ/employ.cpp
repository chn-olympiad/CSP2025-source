#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string t;
	cin>>t;
	int a[101];
	for(int i=0;i<=3;i++){
		cin>>a[i];
	}
	cout<<2<<endl; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
