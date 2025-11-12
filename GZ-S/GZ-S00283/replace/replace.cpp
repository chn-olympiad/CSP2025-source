#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	int fib[100001];
	fib[1]=1;
	fib[2]=1;
	for(int i=3;i<=x;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=fib[i%10+1];j++)
		{
			cout<<" ";
		}
		cout<<"*"<<endl;
	}
	return 0;
}
