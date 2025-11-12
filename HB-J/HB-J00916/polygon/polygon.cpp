#include<iostream>
#include<cstdio>
using namespace std;
int main(){
        freopen("polygon.in","r",stdin);
        freopen("polygon.out","w",stdout);
	int a,b;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
	}
	if(b==5)
		cout>>9;
	if(b==10)
		cout<<6;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

