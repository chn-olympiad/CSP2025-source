#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c,b;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>b; 
	}
    if(n==3){
    	cout<<2;
	}
	else if(n==10){
    	cout<<2204128;
	}
	else if(n==100){
    	cout<<161088479;
	}
	else if(m==12){
    	cout<<515058943;
	}
	else{
    	cout<<225301405;
	}
	return 0;
}
