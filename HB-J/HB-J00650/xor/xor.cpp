#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(NULL));
	int a,b,c;
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>c;
	cout<<rand()%a+1;
	a=a+1;
	//long long OIoveYXF=91;
	return 0;
}
	
